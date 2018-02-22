#include <iostream>
#include "asema.h"
#include "nappula.h"
#include "ruutu.h"

Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vd = new Daami(L"\u2655", 0, VD);
Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);

Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Daami(L"\u265B", 1, MD);
Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);

Asema::Asema(){
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			lauta[i][j] = NULL;
	lauta[0][0] = vt;
	lauta[1][0] = vr;
	lauta[2][0] = vl;
	lauta[3][0] = vd;
	lauta[4][0] = vk;
	lauta[5][0] = vl;
	lauta[6][0] = vr;
	lauta[7][0] = vt;

	lauta[0][1] = vs;
	lauta[1][1] = vs;
	lauta[2][1] = vs;
	lauta[3][1] = vs;
	lauta[4][1] = vs;
	lauta[5][1] = vs;
	lauta[6][1] = vs;
	lauta[7][1] = vs;

	lauta[0][7] = mt;
	lauta[1][7] = mr;
	lauta[2][7] = ml;
	lauta[3][7] = md;
	lauta[4][7] = mk;
	lauta[5][7] = ml;
	lauta[6][7] = mr;
	lauta[7][7] = mt;

	lauta[0][6] = ms;
	lauta[1][6] = ms;
	lauta[2][6] = ms;
	lauta[3][6] = ms;
	lauta[4][6] = ms;
	lauta[5][6] = ms;
	lauta[6][6] = ms;
	lauta[7][6] = ms;

	siirtovuoro = 0;
	onkoValkeaKuningasLiikkunut = false;
	onkoMustaKuningasLiikkunut = false;
	onkoValkeaDTliikkunut = false;
	onkoValkeaKTliikkunut = false;
	onkoMustaDTliikkunut = false;
	onkoMustaKTliikkunut = false;

}
void Asema::paivitaAsema(Siirto *siirto) {

	this->kaksoisaskelSarakkeella = -1;
	if (siirto->onkoLyhytLinna()) {
		if (siirtovuoro == 0) {
			lauta[4][0] = NULL;
			lauta[6][0] = vk;
			lauta[7][0] = NULL;
			lauta[5][0] = vt;
		}
		if (siirtovuoro == 1) {
			lauta[4][7] = NULL;
			lauta[6][7] = mk;
			lauta[7][7] = NULL;
			lauta[5][7] = mt;
		}
	}

	// onko pitk‰ linna
	else if (siirto->onkoPitk‰linna()) {
		if (siirtovuoro == 0) {
			lauta[4][0] = NULL;
			lauta[2][0] = vk;
			lauta[0][0] = NULL;
			lauta[3][0] = vt;
		}
		if (siirtovuoro == 1) {
			lauta[4][7] = NULL;
			lauta[2][7] = mk;
			lauta[0][7] = NULL;
			lauta[3][7] = mt;
		}

	}
	else {

		int ax, ay, lx, ly;

		ax = siirto->getAlkuruutu().getRivi();
		ay = siirto->getAlkuruutu().getSarake();
		Nappula* nappula = lauta[ay][ax];

		lx = siirto->getLoppuruutu().getRivi();
		ly = siirto->getLoppuruutu().getSarake();

		//Kaksoisaskel
		if
		(
			(lauta[ay][ax]->getKoodi() == VS || lauta[ay][ax]->getKoodi() == MS) &&
			(ax - lx == 2 || ax - lx == -2)
		)
			kaksoisaskelSarakkeella = ay;

		// Ohestalyˆnti
		if
		(
			(lauta[ay][ax]->getKoodi() == VS || lauta[ay][ax]->getKoodi() == MS) &&
			(ay != ly) &&
			(lauta[ly][lx] == NULL)
		)
			lauta[ly][ax] = NULL;

		lauta[ay][ax] = NULL;
		lauta[ly][lx] = nappula;
		if (siirto->miksikorotetaan != NULL)
			lauta[ly][lx] = siirto->miksikorotetaan;
		if (nappula->getKoodi() == VK) {
			onkoValkeaKuningasLiikkunut = true;
		}
		if (nappula->getKoodi() == MK) {
			onkoMustaKuningasLiikkunut = true;
		}
		if (nappula->getKoodi() == VT && ay == 7 && ax == 0) {
			onkoValkeaKTliikkunut = true;
		}
		if (nappula->getKoodi() == VT && ay == 0 && ax == 0) {
			onkoValkeaDTliikkunut = true;
		}
		if (nappula->getKoodi() == MT && ay == 7 && ax == 7) {
			onkoMustaKTliikkunut = true;
		}
		if (nappula->getKoodi() == VT && ay == 0 && ax == 7) {
			onkoMustaDTliikkunut = true;
		}

	}
	if (siirtovuoro == 0) {
		siirtovuoro = 1;
	}
	else if (siirtovuoro == 1) {
		siirtovuoro = 0;
	}

}

int Asema::getSiirtovuoro() {
	return this->siirtovuoro;
}
void Asema::setSiirtovuoro(int vuoro) {
	this->siirtovuoro = vuoro;
}
double Asema::evaluoi()
{
	double score = 0;;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getKoodi() == VS) {
				score += 1;
			}
			else if (this->lauta[i][j]->getKoodi() == MS) {
				score -= 1;
			}
			else if (this->lauta[i][j]->getKoodi() == VR) {
				score += 3;
			}
			else if (this->lauta[i][j]->getKoodi() == MR) {
				score -= 3;
			}
			else if (this->lauta[i][j]->getKoodi() == VL) {
				score += 4;
			}
			else if (this->lauta[i][j]->getKoodi() == ML) {
				score -= 4;
			}
			else if (this->lauta[i][j]->getKoodi() == VT) {
				score += 5;
			}
			else if (this->lauta[i][j]->getKoodi() == MT) {
				score -= 5;
			}
			else if (this->lauta[i][j]->getKoodi() == VD) {
				score += 20;
			}
			else if (this->lauta[i][j]->getKoodi() == MD) {
				score -= 20;
			}
		}
	}
	if (this->lauta[3][3] != NULL && (this->lauta[3][3]->getKoodi() == VS || this->lauta[3][3]->getKoodi() == VR)) {
		score += 0.25;
	}
	if (this->lauta[4][3] && (this->lauta[4][3]->getKoodi() == VS || this->lauta[4][3]->getKoodi() == VR)) {
		score += 0.25;
	}
	if (this->lauta[3][4] != NULL && (this->lauta[3][4]->getKoodi() == VS || this->lauta[3][4]->getKoodi() == VR)) {
		score += 0.25;
	}
	if (this->lauta[4][4] != NULL && (this->lauta[4][4]->getKoodi() == VS || this->lauta[4][4]->getKoodi() == VR)) {
		score += 0.25;
	}
	for (int x = 2; x < 6; x++) {
		if (this->lauta[x][2] != NULL && (this->lauta[x][2]->getKoodi() == VS || this->lauta[x][2]->getKoodi() == VR)) {
			score += 0.11;
		}
		if (this->lauta[x][5] != NULL && (this->lauta[x][5]->getKoodi() == VS || this->lauta[x][5]->getKoodi() == VR)) {
			score += 0.11;
		}
	}
	for (int y = 3; y < 5; y++) {
		if (this->lauta[2][y] != NULL && (this->lauta[2][y]->getKoodi() == VS || this->lauta[2][y]->getKoodi() == VR)) {
			score += 0.11;
		}
		if (this->lauta[5][y] != NULL && (this->lauta[5][y]->getKoodi() == VS || this->lauta[5][y]->getKoodi() == VR)) {
			score += 0.11;
		}
	}
	if (this->lauta[3][3] != NULL && (this->lauta[3][3]->getKoodi() == MS || this->lauta[3][3]->getKoodi() == MR)) {
		score -= 0.25;
	}
	if (this->lauta[4][3] != NULL && (this->lauta[4][3]->getKoodi() == MS || this->lauta[4][3]->getKoodi() == MR)) {
		score -= 0.25;
	}
	if (this->lauta[3][4] != NULL && (this->lauta[3][4]->getKoodi() == MS || this->lauta[3][4]->getKoodi() == MR)) {
		score -= 0.25;
	}
	if (this->lauta[4][4] != NULL && (this->lauta[4][4]->getKoodi() == MS || this->lauta[4][4]->getKoodi() == MR)) {
		score -= 0.25;
	}
	for (int x = 2; x < 6; x++) {
		if (this->lauta[x][2] != NULL && (this->lauta[x][2]->getKoodi() == MS || this->lauta[x][2]->getKoodi() == MR)) {
			score -= 0.11;
		}
		if (this->lauta[x][5] != NULL && (this->lauta[x][5]->getKoodi() == MS || this->lauta[x][5]->getKoodi() == MR)) {
			score -= 0.11;
		}
	}
	for (int y = 3; y < 5; y++) {
		if (this->lauta[2][y] != NULL && (this->lauta[2][y]->getKoodi() == MS || this->lauta[2][y]->getKoodi() == MR)) {
			score -= 0.11;
		}
		if (this->lauta[5][y] != NULL && (this->lauta[5][y]->getKoodi() == MS || this->lauta[5][y]->getKoodi() == MR)) {
			score -= 0.11;
		}
	}

	std::list<Siirto> vSiirrot;
	std::list<Siirto> mSiirrot;
	int vari = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->lauta[i][j]->annaSiirrot(vSiirrot, &Ruutu(i, j), this, vari);
		}
	}
	vari = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->lauta[i][j]->annaSiirrot(mSiirrot, &Ruutu(i, j), this, vari);
		}
	}
	score += vSiirrot.size()*0.05;
	score -= mSiirrot.size()*0.05;
	return score;

}

bool Asema::getOnkoValkeaKuningasLiikkunut() {
	return this->onkoValkeaKuningasLiikkunut;
}
bool Asema::getOnkoMustaKuningasLiikkunut() {
	return this->onkoMustaKuningasLiikkunut;
}
bool Asema::getOnkoValkeaDTliikkunut() {
	return this->onkoValkeaDTliikkunut;
}
bool Asema::getOnkoValkeaKTliikkunut() {
	return this->onkoValkeaKTliikkunut;
}
bool Asema::getOnkoMustaDTliikkunut() {
	return this->onkoMustaDTliikkunut;
}
bool Asema::getOnkoMustaKTliikkunut() {
	return this->onkoMustaKTliikkunut;
}
MinMaxPaluu Asema::alphaBeta(double alpha, double beta, int syvyys) {
	MinMaxPaluu paluuarvo;

	// Generoidaan aseman lailliset siirrot.
	std::list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);

	if (siirrot.size() == 0)
	{
		// *** TODO ***
		// tutki kumpi ja palauta sen mukainen arvo (tasapeli 0). pohja alku ei max..
		paluuarvo.evaluointiArvo = 0;
		return paluuarvo;
	}

	if (syvyys == 0)
	{
		paluuarvo.evaluointiArvo = evaluoi();
		return paluuarvo;
	}
	if (siirtovuoro == 0) {
		paluuarvo.evaluointiArvo = alpha;
	}
	else if (siirtovuoro == 1) {
		paluuarvo.evaluointiArvo = beta;
	}
	for (auto s : siirrot)
	{
		Asema uusi_asema = *this;
		uusi_asema.paivitaAsema(&s);
		MinMaxPaluu arvo = uusi_asema.alphaBeta(alpha, beta, syvyys - 1);
		if
			((siirtovuoro == 0 && arvo.evaluointiArvo > paluuarvo.evaluointiArvo) || (siirtovuoro == 1 && arvo.evaluointiArvo < paluuarvo.evaluointiArvo))
		{
			paluuarvo.evaluointiArvo = arvo.evaluointiArvo;
			paluuarvo.parasSiirto = s;
		}
	}
	//std::wcout << syvyys << std::endl;
	//std::wcout << "lopullinen: " << paluuarvo.evaluointiArvo << std::endl;
	//std::wcout << "paras siirto: " << paluuarvo.parasSiirto.getAlkuruutu().getRivi() << ", " << paluuarvo.parasSiirto.getAlkuruutu().getSarake() << " - > " << paluuarvo.parasSiirto.getLoppuruutu().getRivi() << ", " << paluuarvo.parasSiirto.getLoppuruutu().getSarake() << std::endl;
	return paluuarvo;
}

MinMaxPaluu Asema::minimax(int syvyys)
{
	MinMaxPaluu paluuarvo;
	std::list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);

	Ruutu kuninkaanRuutu;
	
	if (siirrot.size() == 0)
	{
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->lauta[x][y] != NULL) {
					if (this->lauta[x][y]->getKoodi() == VK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		if (this->onkoRuutuUhattu(&kuninkaanRuutu, 1)) {
			paluuarvo.evaluointiArvo = -1000000;
			return paluuarvo;
		}
		if (!this->onkoRuutuUhattu(&kuninkaanRuutu, 1)) {
			paluuarvo.evaluointiArvo = 0;
			return paluuarvo;
		}
	}

	if (syvyys == 0)
	{
		paluuarvo.evaluointiArvo = evaluoi();
		return paluuarvo;
	}
	paluuarvo.evaluointiArvo = (siirtovuoro == 0 ? -1000000 : 100000);
	for (auto s : siirrot)
	{
		Asema uusi_asema = *this;
		uusi_asema.paivitaAsema(&s);
		MinMaxPaluu arvo = uusi_asema.minimax(syvyys - 1);
		if
			((siirtovuoro == 0 && arvo.evaluointiArvo > paluuarvo.evaluointiArvo) || (siirtovuoro == 1 && arvo.evaluointiArvo < paluuarvo.evaluointiArvo))
		{
			paluuarvo.evaluointiArvo = arvo.evaluointiArvo;
			paluuarvo.parasSiirto = s;
		}
	}
	return paluuarvo;
}


bool Asema::onkoRuutuUhattu(Ruutu* ruutu, int vastustajanVari){
	std::list<Siirto> vastustajaSiirrotLista;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getVari() == vastustajanVari)
				this->lauta[i][j]->annaSiirrot(vastustajaSiirrotLista, &Ruutu(i, j), this, vastustajanVari);
		}
	}
	bool ruutuOk = true;
	for (auto s : vastustajaSiirrotLista)
	{
		if (ruutu->getSarake() == s.getLoppuruutu().getSarake() && ruutu->getRivi() == s.getLoppuruutu().getRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;
}

void Asema::huolehdiKuninkaanShakeista(std::list<Siirto>& lista, int vari) { 																			
	int kuninkaanX;
	int kuninkaanY;
	int koodi;
	if (vari == 0) {
		koodi = VK;
	}
	else {
		koodi = MK;
	}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (this->lauta[i][j] == NULL)
					continue;
				if (this->lauta[i][j]->getKoodi() == koodi) {
					kuninkaanX = i;
					kuninkaanY = j;
					break;
				}
			}
		}
	
	Asema testiAsema;
	std::list<Siirto> siivottuSiirrotLista;
	for (auto s : lista) {
		testiAsema = *this;
		testiAsema.paivitaAsema(&s);
		int x, y;

		// Kuninkaan siirto?
		if (s.onkoLyhytLinna())
		{
			x = 6;
			if (this->getSiirtovuoro() == 0)
				y = 0;
			else
				y = 7;
		}
		else if (s.onkoPitk‰linna())
		{
			x = 2;
			if (this->getSiirtovuoro() == 0)
				y = 0;
			else
				y = 7;
		}
		else
		{
			Nappula* siirtyva = this->lauta[s.getAlkuruutu().getSarake()][s.getAlkuruutu().getRivi()];
			if (siirtyva->getKoodi() == VK || siirtyva->getKoodi() == MK)
			{
				x = s.getLoppuruutu().getSarake();
				y = s.getLoppuruutu().getRivi();
			}
			else
			{
				// Ei ole, kuninkaan sijainti sama kuin ennen siirron s kokeilua
				x = kuninkaanX;
				y = kuninkaanY;
			}
		}

		// huom !vari
		if (testiAsema.onkoRuutuUhattu(&Ruutu(x, y), !vari) == true) {
			siivottuSiirrotLista.push_back(s);
		}
	}
	lista = siivottuSiirrotLista;
}

void Asema::annaLinnoitusSiirrot(std::list<Siirto>& lista, int vari){
	//// Linnoituksien huomioiminen
	//// 1. Kuningas ei saa olla liikkunut
	//// 2. Torni ei saa olla liikkunut
	//// 3. Kuningas ei saa olla shakattuna
	//// 4. Ruutujen pit‰‰ olla tyhj‰t
	//// 5. Ruudut eiv‰t saa olla uhattuja
	if (vari == 0) {
		//valkean lyhyt linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaKTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 0), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(5, 0), !vari) && this->onkoRuutuUhattu(&Ruutu(6, 0), !vari)
			&& this->lauta[5][0] == NULL && this->lauta[6][0] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lis‰t‰‰n listaan lyhyt linna
		}
		//valkean pitk‰ linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaDTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 0), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(3, 0), !vari) && this->onkoRuutuUhattu(&Ruutu(3, 0), !vari)
			&& this->lauta[3][0] == NULL && this->lauta[2][0] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lis‰t‰‰n listaan lyhyt linna
		}
	}
	if (vari == 1) {
		//mustan lyhyt linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaKTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 7), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(5, 7), !vari) && this->onkoRuutuUhattu(&Ruutu(6, 7), !vari)
			&& this->lauta[5][7] == NULL && this->lauta[6][7] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lis‰t‰‰n listaan lyhyt linna
		}
		//mustan pitk‰ linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaDTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 7), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(3, 7), !vari) && this->onkoRuutuUhattu(&Ruutu(3, 7), !vari)
			&& this->lauta[3][7] == NULL && this->lauta[2][7] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lis‰t‰‰n listaan lyhyt linna
		}
	}
}

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista) {
	int vari = this->getSiirtovuoro();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->lauta[i][j] == NULL) {
				continue;
			}
			if (this->lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->lauta[i][j]->annaSiirrot(lista, &Ruutu(i, j), this, vari);
		}
	}
	this->annaLinnoitusSiirrot(lista, vari);
	this->huolehdiKuninkaanShakeista(lista, vari);
}
