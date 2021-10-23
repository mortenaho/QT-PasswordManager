#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

    void on_tbl_pass_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void showData();
};
#endif // MAINWINDOW_H
