#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_examenPractic.h"

class examenPractic : public QMainWindow
{
    Q_OBJECT

public:
    examenPractic(QWidget *parent = nullptr);
    ~examenPractic();

private:
    Ui::examenPracticClass ui;
};
