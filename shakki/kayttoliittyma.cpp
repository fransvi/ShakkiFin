#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include<string>
#include "kayttoliittyma.h"

using namespace std;

Asema* asema;

Kayttoliittyma* Kayttoliittyma::instance = nullptr;

Kayttoliittyma::Kayttoliittyma()
{
}

Kayttoliittyma * Kayttoliittyma::getInstance()
{
	if (instance == nullptr) {

		instance = new Kayttoliittyma();
	}
	return instance;
}
void Kayttoliittyma::piirraLauta()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 7; i >= 0; i--){
		for (int j = 0; j < 8; j++){
			if (j == 0 && i == 7){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 8;
			}
			if (j == 0 && i == 6){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 7;
			}
			if (j == 0 && i == 5){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 6;
			}
			if (j == 0 && i == 4){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 5;
			}
			if (j == 0 && i == 3){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 4;
			}
			if (j == 0 && i == 2){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 3;
			}
			if (j == 0 && i == 1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 2;
			}
			if (j == 0 && i == 0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				wcout << 1;
			}
			if (i % 2 != 0){
				if (j % 2 == 0)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
			}
			else {
				if (j % 2 != 0)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
					BACKGROUND_GREEN | BACKGROUND_BLUE);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
			}
			
			if (asema->lauta[j][i] != NULL){
				wcout <<" "<< asema->lauta[j][i]->getUnicode()<<" ";
			}
			else{
				wcout << "   ";
			}
		}
		wcout << "\n";
	}
	wcout << "  " << "a " << " b " << " c " << " d " << " e " << " f " << " g " << " h \n";
}

Siirto Kayttoliittyma::annaVastustajanSiirto(){
	int lahtoX;
	int lahtoY;
	int tuloX;
	int tuloY;


	do{
		wcout << "Anna siirtosi esim. (Rg1-f3),\n linnoitus annetaan 0-0 tai 0-0-0";
		wcin >> siirtoString;
		if (siirtoString == L"0-0" || siirtoString == L"0-0-0") {
			if (siirtoString == L"0-0") {
				return Siirto(true, false);
			}
			if (siirtoString == L"0-0-0") {
				return Siirto(false, true);
			}
		}
		else if (siirtoString.length() == 6){
			siirtynytNappulaString = siirtoString[0];
			siirtoString.erase(0, 1);
		}
		else{
			siirtynytNappulaString = L"s";
		}
		lahtoX = siirtoString[0] - 'a';
		lahtoY = siirtoString[1] - '1';
		tuloX = siirtoString[3] - 'a';
		tuloY = siirtoString[4] - '1';
	
		if (((lahtoX < 0 || lahtoX >7) || (lahtoY < 0 || lahtoY > 7)) || ((tuloX < 0 || tuloX >7) || (tuloY < 0 || tuloY > 7)))
			wcout << "Siirron t�ytyy olla muotoa esim. Rf1-f3,\n aakkoset v�lilt� a-h\n numerot v�lilt� 1-8,\n Nappula on (K,k),(D,d),(T,t),(R,r),(L,l)\n sotilas j�tet��n merkitsem�tt�\n";
	} while (((lahtoX < 0 || lahtoX >7) || (lahtoY < 0 || lahtoY > 7)) || ((tuloX < 0 || tuloX >7) || (tuloY < 0 || tuloY > 7)));
	
	Ruutu lahtoRuutu(lahtoX, lahtoY);
	Ruutu tuloRuutu(tuloX, tuloY);
	Siirto siirto(lahtoRuutu, tuloRuutu);
	std::wstring korotettuNappula;
	if (siirtynytNappulaString == L"s" && (tuloY == 0 || tuloY == 7)) {
		std::wcout << "Miksi nappulaksi haluat korottaa? (esim. D)\n";
		std::wcin >> korotettuNappula;
		if (tuloY == 7) {
			if (korotettuNappula == L"D" || korotettuNappula == L"d") {
				siirto.miksikorotetaan = asema->vd;
			}
			if (korotettuNappula == L"T" || korotettuNappula == L"t") {
				siirto.miksikorotetaan = asema->vt;
			}
			if (korotettuNappula == L"R" || korotettuNappula == L"r") {
				siirto.miksikorotetaan = asema->vr;
			}
			if (korotettuNappula == L"L" || korotettuNappula == L"l") {
				siirto.miksikorotetaan = asema->vl;
			}
		}

		if (tuloY == 0) {
			if (korotettuNappula == L"D" || korotettuNappula == L"d") {
				siirto.miksikorotetaan = asema->md;
			}
			if (korotettuNappula == L"T" || korotettuNappula == L"t") {
				siirto.miksikorotetaan = asema->mt;
			}
			if (korotettuNappula == L"R" || korotettuNappula == L"r") {
				siirto.miksikorotetaan = asema->mr;
			}
			if (korotettuNappula == L"L" || korotettuNappula == L"l") {
				siirto.miksikorotetaan = asema->ml;
			}
		}
	}
	
	return siirto;
	
}
int Kayttoliittyma::kysyVastustajanVari(){
	int vari;
	wcout << "Anna vari milla haluat pelata (Valkea 0; Musta 1)";
	cin >> vari;
	return vari;
}