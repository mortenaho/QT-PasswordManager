#ifndef DTPASS_H
#define DTPASS_H

#include <QMainWindow>

namespace Ui {
class dtpass;
}

class dtpass : public QMainWindow
{
    Q_OBJECT

public:
    explicit dtpass(QWidget *parent = nullptr);
    ~dtpass();

private:
    Ui::dtpass *ui;
};

#endif // DTPASS_H
