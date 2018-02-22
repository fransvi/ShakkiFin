#pragma once
#include "asema.h"
#include "siirto.h"
#include "nappula.h"
#include "peli.h"

class Kayttoliittyma{

public:

	static Kayttoliittyma * getInstance();
	Asema* asema;

	void piirraLauta();
	Siirto annaVastustajanSiirto();
	int kysyVastustajanVari();
	//Nappula annaSiirtynytNappula();
private:
	Siirto siirto;
	Kayttoliittyma();
	static Kayttoliittyma* instance;
	std::wstring siirtoString;
	std::wstring siirtynytNappulaString;
	Ruutu *lahtoRuutu;
};