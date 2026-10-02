#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Spravca_autoservisu.h"

class Spravca_autoservisu : public QMainWindow
{
    Q_OBJECT

public:
    Spravca_autoservisu(QWidget *parent = nullptr);
    ~Spravca_autoservisu();

private:
    Ui::Spravca_autoservisuClass ui;
};

