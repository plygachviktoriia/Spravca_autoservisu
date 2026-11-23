#pragma once
#include <QVector>
#include <QString>
#include "Auto.h"
#include "Osobny.h"
#include "Uzitkovy.h"

class AutoservisManager
{
private:
	QVector <Auto*> list_aut;
	QVector <Osobny*> list_osobny;
	QVector <Uzitkovy*> list_uzitkovy;

public:
	AutoservisManager() {}

	bool LoadFILE(const QString& cesta);
	bool SaveFILE(const QString& cesta);

	void ClearFILE()
	{
		int size_auta = list_aut.size();

		for (int i = 0; i < size_auta; i++)
		{
			delete list_aut[i];
		}

		list_aut.clear();
		list_uzitkovy.clear();
		list_osobny.clear();
	}

	QVector<Auto*> Vsetky()  { return list_aut; }
	QVector<Uzitkovy*> Vsetky_Uzitkovy() { return list_uzitkovy; }
	QVector<Osobny*> Vsetky_Osobny() { return list_osobny; }
	QVector<Auto*> PodlaStavu(bool stav);

	~AutoservisManager()
	{
		int size = list_aut.size();
		for (int i = 0; i < size; i++)
		{
			delete list_aut[i];
		}
	}
};

