#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSqlTableModel>
#include <db.h>

db mm;
int rowid=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mm=db();
    ui->setupUi(this);
    showData();
}




MainWindow::~MainWindow()
{
    delete ui;
}

QSqlTableModel  *m_tbModel;
void MainWindow::on_btn_save_clicked()
{
    if(rowid==0)
        mm.execute("insert into passwords (title,url,username,pass) values ('"+ui->txt_title->text()+"','"+ui->txt_url->text()+"','"+ui->txt_username->text()+"','"+ui->txt_password->text()+"')");
    else{
        mm.execute("update passwords set title='"+ui->txt_title->text()+"',url='"+ui->txt_url->text()+"',username='"+ui->txt_username->text()+"',pass='"+ui->txt_password->text()+"' where id="+QString::number(rowid)+"");

    }
    showData();
}


void MainWindow::on_btn_cancel_clicked()
{
    ui->txt_title->setText("");
    ui->txt_password->setText("");
    ui->txt_url->setText("");
    ui->txt_username->setText("");

}
void MainWindow::showData(){
    m_tbModel =new QSqlTableModel(this,mm.m_db);

    m_tbModel->setTable("passwords"); //نام جدول مورد نظر

    m_tbModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//در این خط گفته شده وقتی فیلدی در جدول تغییر کرد آن را دریتا بیس لحاظ نکن و منتظر بمان تا دستور ذخیره بصورت دستی وارد شود.

    m_tbModel->select();

    ui->tbl_pass->setModel(m_tbModel);

    ui->tbl_pass->setColumnWidth(0,10);


}

void MainWindow::on_tbl_pass_doubleClicked(const QModelIndex &index)
{
    rowid=ui->tbl_pass->model()->index(index.row(),0).data().toInt();
    ui->txt_title->setText(ui->tbl_pass->model()->index(index.row(),1).data().toString());
    ui->txt_url->setText(ui->tbl_pass->model()->index(index.row(),2).data().toString());
    ui->txt_username->setText(ui->tbl_pass->model()->index(index.row(),3).data().toString());
    ui->txt_password->setText(ui->tbl_pass->model()->index(index.row(),4).data().toString());
}

