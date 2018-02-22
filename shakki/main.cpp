#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include "kayttoliittyma.h"
#include "Siirto.h"
#include "asema.h"
#include "peli.h"

using namespace std; 

int main()
{
	int lopetus = 100;
	Asema asema;
	list<Siirto>::iterator lit;
	Kayttoliittyma* kayttoliittyma = Kayttoliittyma::getInstance();
	kayttoliittyma->asema = &asema; 
	Peli peli(kayttoliittyma->kysyVastustajanVari());
	std::list<Siirto> lista;
	system("cls");
	int koneenVari = peli.getKoneenVari();

	while (lopetus != 0) {
		lista.clear();
		kayttoliittyma->piirraLauta();
		asema.annaLaillisetSiirrot(lista);
		/*for each(Siirto s in lista) {
			wcout << "OK siirto: (y: " << s.getAlkuruutu().getRivi() << ", x: " << s.getAlkuruutu().getSarake() << ") loppuruutu: (y: " << s.getLoppuruutu().getRivi() << ", x:" << s.getLoppuruutu().getSarake() << ")" << endl;
		}*/
		double asemanArvo = asema.evaluoi();
		//std::wcout << "Aseman arvo: " << asemanArvo;
		if (lista.size() == 0) {
			lopetus = 0;
			std::wcout << "Peli loppui";
			continue;
		}
		Siirto siirto;
		if (asema.getSiirtovuoro() == koneenVari) {
				double asemanArvo = asema.evaluoi();
				wcout << " KONEEN SIIRTO" << endl;
				//wcout << asemanArvo << endl;;
				//MinMaxPaluu mp = asema.alphaBeta(-1000000.0, 1000000.0, 4);
				MinMaxPaluu mp = asema.minimax(3);
				//wcout << mp.parasSiirto.getAlkuruutu().getSarake() << ", " << mp.parasSiirto.getAlkuruutu().getRivi() << " - > " << mp.parasSiirto.getLoppuruutu().getSarake() << ", " << mp.parasSiirto.getLoppuruutu().getRivi() << endl;
				siirto = mp.parasSiirto;
			}
		else {
			siirto = kayttoliittyma->annaVastustajanSiirto();
		}
		asema.paivitaAsema(&siirto);

	}

	
	return 0;
}