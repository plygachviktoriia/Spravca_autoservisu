#include "Spravca_autoservisu.h"

Spravca_autoservisu::Spravca_autoservisu(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Spravca_autoservisu::~Spravca_autoservisu()
{}

void Spravca_autoservisu::FillTable(QVector<Auto*> auta)
{
}

void Spravca_autoservisu::on_actionLoad_triggered()
{

}

void Spravca_autoservisu::on_actionSave_triggered()
{

}

void  Spravca_autoservisu::on_SelectAutoComboBox_selected(int index)
{
    index = ui.SelectAutoComboBox->currentIndex();

    if (index == 0)
    {
        

    }
}

void  Spravca_autoservisu::on_ApplyFilter_clicked()
{
    switch (ui.SelectAutoComboBox->currentIndex())
    {
    case 0:
        FillTable(manager.Vsetky());
        break;

    case 1:
        FillTable(manager.PodlaStavu(true));
        break;
       
    case 2:
        FillTable(manager.PodlaStavu(false));
        break;
    }
}

void  Spravca_autoservisu::on_DeclineFilter_clicked()
{
    ui.SelectAutoComboBox->setCurrentIndex(0);
    FillTable(manager.Vsetky());
}

void  Spravca_autoservisu::on_ChangeStatus_clicked()
{
    
}