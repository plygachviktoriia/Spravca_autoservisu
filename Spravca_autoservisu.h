#pragma once
#include "Osobny.h"
#include "Uzitkovy.h"
#include "Auto.h"
#include "AutoservisManager.h"

#include <QtWidgets/QMainWindow>
#include "ui_Spravca_autoservisu.h"
#include <QString>
#include <QVector>

class Spravca_autoservisu : public QMainWindow
{
    Q_OBJECT

public:
    Spravca_autoservisu(QWidget *parent = nullptr);
    ~Spravca_autoservisu();
    void FillTable(QVector<Auto*> auta);
   

private:
    Ui::Spravca_autoservisuClass ui;
    AutoservisManager manager;

public slots:

    // ULOZENIE A NACITANIE SUBORU
    void on_actionLoad_triggered();
    void on_actionSave_triggered();

    void on_SelectAutoComboBox_selected(int index);
    void on_ApplyFilter_clicked();
    void on_DeclineFilter_clicked();
    void on_ChangeStatus_clicked();
};

