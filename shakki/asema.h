#pragma once
#include <list>
#include <string>
#include "siirto.h"
#include "MinMaxPaluu.h"
class LaillisetSiirrot;
class Nappula;

class Asema{

public:
	//Konstruktori luo alkuaseman laudalle
	//Valkea väri = 0, musta väri = 1
	Asema();
	Nappula* lauta[8][8];
	static Nappula* vk;
	static Nappula* vd;
	static Nappula* vt;
	static Nappula* vl;
	static Nappula* vr;
	static Nappula* vs;

	static Nappula* mk;
	static Nappula* md;
	static Nappula* mt;
	static Nappula* ml;
	static Nappula* mr;
	static Nappula* ms;


	void paivitaAsema(Siirto*);
	//Nappula annaNappulaRuudusta(Ruutu*);
	void annaLaillisetSiirrot(std::list<Siirto>& lista);
	int getSiirtovuoro();
	void setSiirtovuoro(int);
	double evaluoi();
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaDTliikkunut();
	bool getOnkoMustaKTliikkunut();
	MinMaxPaluu alphaBeta(double alpha, double beta, int syvyys);
	MinMaxPaluu alphaBeta(int alpha, int beta, int syvyys);
	MinMaxPaluu minimax(int syvyys);
	int kaksoisaskelSarakkeella = -1;


	
private:

	bool onkoRuutuUhattu(Ruutu*, int vastustajanVari);
	void huolehdiKuninkaanShakeista(std::list<Siirto>& lista, int vari); // poistaa listasta siirrot jotka vievät kuninkaan shakkiin
	void annaLinnoitusSiirrot(std::list<Siirto>& lista, int vari);

	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTliikkunut;
	bool onkoValkeaKTliikkunut;
	bool onkoMustaDTliikkunut;
	bool onkoMustaKTliikkunut;
};