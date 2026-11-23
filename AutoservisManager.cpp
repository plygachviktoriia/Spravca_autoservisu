#include "AutoservisManager.h"
#include "Osobny.h"
#include "Uzitkovy.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>

using namespace std;

bool AutoservisManager::LoadFILE(const QString& cesta)
{
    QFile file(cesta);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Nepodarilo sa otvorit subor" << file.errorString();
        return false;
    }

    ClearFILE();
    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();

        if (line.trimmed().isEmpty()) { continue; }

        QStringList parts = line.split(',');
        if (parts.size() < 6) { continue; }

        QString typ_auta = parts[0].trimmed();
        QString marka = parts[1].trimmed();
        QString model = parts[2].trimmed();
        QString rok = parts[3].trimmed();
        QString km_firma = parts[4].trimmed();
        QString status = parts[5].trimmed();

        if (typ_auta == "Car") 
        { 
            string string_marka = marka.toStdString();
            string string_model = model.toStdString();
            int int_rok = rok.toInt();
            int int_km = km_firma.toInt();
            bool bool_status = status.toInt();

            Osobny* osobny_new = new Osobny(string_marka, string_model, int_rok, int_km, bool_status);

            list_aut.push_back(osobny_new);
            list_osobny.push_back(osobny_new);
        }
        else if (typ_auta == "CommercialCar") 
        {
            string string_marka = marka.toStdString();
            string string_model = model.toStdString();
            int int_rok = rok.toInt();
            string string_firma = km_firma.toStdString();
            bool bool_status = status.toInt();

            Uzitkovy* uzitkovy_new = new Uzitkovy(string_marka, string_model, int_rok, string_firma, bool_status);

            list_aut.push_back(uzitkovy_new);
            list_uzitkovy.push_back(uzitkovy_new);
        }
        else { continue; }
    }

    file.close();

    return true;
}

bool AutoservisManager::SaveFILE(const QString& cesta)
{
    return true;
}

QVector<Auto*> AutoservisManager::PodlaStavu(bool stav)
{
    QVector<Auto*> vysledok;
    int size = list_aut.size();

    for (int i = 0; i < size; i++)
    {
        if (list_aut[i]->Get_servis() == stav)
        {
            vysledok.push_back(list_aut[i]);
        }
    }

    return vysledok;
}