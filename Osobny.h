#pragma once
#include <iostream>
#include <string>
#include "Auto.h"
using namespace std;

class Osobny : public Auto 
{
private:
	int km;

public:
	Osobny() : Auto(), km(0) {}
	Osobny(string za, string ma, int rv, int najkm, bool bvs) : Auto(za, ma, rv, bvs), km(najkm) {}

	// SETTER
	void Set_km(int kmset) { km = kmset; }

	// GETTER
	int Get_km() { return km; }

	string CSV()
	{
		return "Car, " + znacka_auta + ", " + model_auta + ", " + to_string(rok_vyroby) + ", " + to_string(km) + ", " + to_string(bol_v_servise);
	}

	~Osobny () {}
};

