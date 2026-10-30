#pragma once
#include <iostream>
#include <string>

using namespace std;

class Auto
{
protected:
	string znacka_auta;
	string model_auta;
	int rok_vyroby;
	bool bol_v_servise;

public:
	Auto() : znacka_auta(""), model_auta(""), rok_vyroby(0), bol_v_servise(0) {}
	Auto(string za, string ma, int rv, bool bvs) : znacka_auta(za), model_auta(ma), rok_vyroby(rv), bol_v_servise(bvs) {}

	// SETTER
	void Set_znacka(const string za) { znacka_auta = za; }
	void Set_model(const string ma) { model_auta = ma; }
	void Set_rok_vyroby(int rv) { rok_vyroby = rv; }
	void Set_servis(bool servis) { bol_v_servise = servis; }

	// GETTER
	string Get_znacka() { return znacka_auta; }
	string Get_model() { return model_auta; }
	int Get_rok() { return rok_vyroby; }
	bool Get_servis() { return bol_v_servise; }

	virtual string CSV() = 0;

	virtual ~Auto() {}
};

