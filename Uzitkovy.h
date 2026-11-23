#pragma once
#include <iostream>
#include <string>
#include "Auto.h"
using namespace std;

class Uzitkovy : public Auto
{
private:
	string nazov_firmy;

public:
	Uzitkovy() : Auto(), nazov_firmy("") {}
	Uzitkovy(string za, string ma, int r, string nf, bool vservise) : Auto(za, ma, r, vservise), nazov_firmy(nf) {}

	// SETTER
	void Set_NazovFirmy(string nazov) { nazov_firmy = nazov; }

	// GETTER
	string Get_NazovFirmy() { return nazov_firmy; }

	string CSV()
	{
		return "CommercialCar," + znacka_auta + "," + model_auta + "," + to_string(rok_vyroby) + "," + nazov_firmy + "," + to_string(bol_v_servise);
	}

	~Uzitkovy() {}
};

