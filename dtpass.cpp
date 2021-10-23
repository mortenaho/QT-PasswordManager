#include "dtpass.h"
#include "ui_dtpass.h"

dtpass::dtpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dtpass)
{
    ui->setupUi(this);
}

dtpass::~dtpass()
{
    delete ui;
}
