#include <list>
#include <string>
#include "asema.h"
#include "nappula.h"


using namespace std;

Nappula::Nappula(wstring unicode, int vari, int koodi){
	this->unicode = unicode;
	this->vari = vari;
	this->_koodi = koodi;
}


wstring Nappula::getUnicode(){
	return unicode;
}
int Nappula::getVari(){
	return vari;
}

int Nappula::getKoodi() {
	return _koodi;
}


void Torni::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int y = ruutu->getRivi(), x = ruutu->getSarake(), lrv, trv;
	lrv = asema->lauta[x][y]->getVari();
	for (int i = x + 1; i < 8; i++) {
		if (asema->lauta[i][y] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, y)));
		}
		else if (asema->lauta[i][y] != NULL) {
			trv = asema->lauta[i][y]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, y)));
				break;
			}
		}
	}
	for (int i = x - 1; i >= 0; i--) {
		if (asema->lauta[i][y] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, y)));
		}
		else if (asema->lauta[i][y] != NULL) {
			trv = asema->lauta[i][y]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, y)));
				break;
			}
		}
	}
	for (int i = y + 1; i < 8; i++) {
		if (asema->lauta[x][i] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x, i)));
		}
		else if (asema->lauta[x][i] != NULL) {
			trv = asema->lauta[x][i]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x, i)));
				break;
			}
		}
	}
	for (int i = y - 1; i >= 0; i--) {
		if (asema->lauta[x][i] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x, i)));
		}
		else if (asema->lauta[x][i] != NULL) {
			trv = asema->lauta[x][i]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x, i)));
				break;
			}
		}
	}
}

void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int y = ruutu->getRivi(), x = ruutu->getSarake(), lrv, trv;
	lrv = asema->lauta[x][y]->getVari();
	if (x + 1 < 8 && y + 2 < 8) {
		if (asema->lauta[x + 1][y + 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x + 1, y + 2)));
		}
		else if (asema->lauta[x + 1][y + 2] != NULL) {
			trv = asema->lauta[x + 1][y + 2]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x + 1, y + 2)));
			}
		}
	}
	if (x + 1 < 8 && y - 2 >= 0) {
		if (asema->lauta[x + 1][y - 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x + 1, y - 2)));
		}
		else if (asema->lauta[x + 1][y - 2] != NULL) {
			trv = asema->lauta[x + 1][y - 2]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x + 1, y - 2)));
			}
		}
	}
	if (x - 1 >= 0 && y + 2 < 8) {
		if (asema->lauta[x - 1][y + 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x - 1, y + 2)));
		}
		else if (asema->lauta[x - 1][y + 2] != NULL) {
			trv = asema->lauta[x - 1][y + 2]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x - 1, y + 2)));
			}
		}
	}
	if (x - 1 >= 0 && y - 2 >= 0) {
		if (asema->lauta[x - 1][y - 2] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x - 1, y - 2)));
		}
		else if (asema->lauta[x - 1][y - 2] != NULL) {
			trv = asema->lauta[x - 1][y - 2]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x - 1, y - 2)));
			}
		}
	}
	if (x + 2 < 8 && y + 1 < 8) {
		if (asema->lauta[x + 2][y + 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x + 2, y + 1)));
		}
		else if (asema->lauta[x + 2][y + 1] != NULL) {
			trv = asema->lauta[x + 2][y + 1]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x + 2, y + 1)));
			}
		}
	}
	if (x + 2 < 8 && y - 1 >= 0) {
		if (asema->lauta[x + 2][y - 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x + 2, y - 1)));
		}
		else if (asema->lauta[x + 2][y - 1] != NULL) {
			trv = asema->lauta[x + 2][y - 1]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x + 2, y - 1)));
			}
		}
	}
	if (x - 2 >= 0 && y + 1 < 8) {
		if (asema->lauta[x - 2][y + 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x - 2, y + 1)));
		}
		else if (asema->lauta[x - 2][y + 1] != NULL) {
			trv = asema->lauta[x - 2][y + 1]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x - 2, y + 1)));
			}
		}
	}
	if (x - 2 >= 0 && y - 1 >= 0) {
		if (asema->lauta[x - 2][y - 1] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(x - 2, y - 1)));
		}
		else if (asema->lauta[x - 2][y - 1] != NULL) {
			trv = asema->lauta[x - 2][y - 1]->getVari();
			if (lrv == trv) {
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(x - 2, y - 1)));
			}
		}
	}
}

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int y = ruutu->getRivi(), x = ruutu->getSarake() ,lrv, trv, j;
	lrv = asema->lauta[x][y]->getVari();
	// viistorivi ruudusta oikealle ylös
	for (int i = x + 1; i < 8; i++) {
		if (i == x + 1) {
			j = y + 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			trv = asema->lauta[i][j]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}

		}
		j++;
	}

	// viistorivi ruudusta oikealle alas
	for (int i = x + 1; i < 8; i++) {
		if (i == x + 1) {
			j = y - 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			trv = asema->lauta[i][j]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}
		}

		j--;
	}

	// viistorivi ruudusta vasemmalle ylös
	for (int i = x - 1; i >= 0; i--) {
		if (i == x - 1) {
			j = y + 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			trv = asema->lauta[i][j]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}
		}

		j++;
	}
	// viistorivi ruudusta vasemmalle alas
	for (int i = x - 1; i >= 0; i--) {
		if (i == x - 1) {
			j = y - 1;
		}
		if (j < 0 || j > 7 || i < 0 || i > 7) {
			break;
		}
		if (asema->lauta[i][j] == NULL) {
			lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
		}
		else if (asema->lauta[i][j] != NULL) {
			trv = asema->lauta[i][j]->getVari();
			if (lrv == trv) {
				break;
			}
			if (lrv != trv) {
				lista.push_back(Siirto(*ruutu, Ruutu(i, j)));
				break;
			}
		}

		j--;
	}
}

void Daami::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	this->Lahetti::annaSiirrot(lista, ruutu, asema, vari);
	this->Torni::annaSiirrot(lista, ruutu, asema, vari);
}

void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu* r, Asema* asema, int vari)
{
	int y = r->getRivi(), x = r->getSarake(), lrv, trv;
	lrv = asema->lauta[x][y]->getVari();
	if (x + 1 < 8) {
		if (asema->lauta[x + 1][y] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x + 1, y)));
		}
		else if (asema->lauta[x + 1][y] != NULL) {
			trv = asema->lauta[x + 1][y]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x + 1, y)));
			}
		}
	}

	if (x + 1 < 8 && y + 1 < 8) {
		if (asema->lauta[x + 1][y + 1] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x + 1, y + 1)));

		}
		else if (asema->lauta[x + 1][y + 1] != NULL) {
			trv = asema->lauta[x + 1][y + 1]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x + 1, y + 1)));

			}
		}
	}

	if (x + 1 < 8 && y - 1 >= 0) {
		if (asema->lauta[x + 1][y - 1] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x + 1, y - 1)));

		}
		else if (asema->lauta[x + 1][y - 1] != NULL) {
			trv = asema->lauta[x + 1][y - 1]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x + 1, y - 1)));

			}
		}
	}

	if (x - 1 >= 0) {
		if (asema->lauta[x - 1][y] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x - 1, y)));
		}
		else if (asema->lauta[x - 1][y] != NULL) {
			trv = asema->lauta[x - 1][y]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x - 1, y)));
			}
		}
	}

	if (x - 1 >= 0 && y + 1 < 8) {
		if (asema->lauta[x - 1][y + 1] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x - 1, y + 1)));
		}
		else if (asema->lauta[x - 1][y + 1] != NULL) {
			trv = asema->lauta[x - 1][y + 1]->getVari();
			if (lrv != trv) {

				lista.push_back(Siirto(*r, Ruutu(x - 1, y + 1)));

			}
		}
	}

	if (x - 1 >= 0 && y - 1 >= 0) {
		if (asema->lauta[x - 1][y - 1] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x - 1, y - 1)));
		}
		else if (asema->lauta[x - 1][y - 1] != NULL) {
			trv = asema->lauta[x - 1][y - 1]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x - 1, y - 1)));
			}
		}
	}

	if (y + 1 < 8) {
		if (asema->lauta[x][y + 1] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x, y + 1)));
		}
		else if (asema->lauta[x][y + 1] != NULL) {
			trv = asema->lauta[x][y + 1]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x, y + 1)));
			}
		}
	}

	if (y - 1 >= 0) {
		if (asema->lauta[x][y - 1] == NULL) {
			lista.push_back(Siirto(*r, Ruutu(x, y - 1)));
		}
		else if (asema->lauta[x][y - 1] != NULL) {
			trv = asema->lauta[x][y - 1]->getVari();
			if (lrv != trv) {
				lista.push_back(Siirto(*r, Ruutu(x, y - 1)));
			}
		}
	}
}

void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int y = ruutu->getRivi(), x = ruutu->getSarake(),lrv,trv;
	lrv = asema->lauta[x][y]->getVari();
	if (y == 1 && lrv == 0) {
		for (int i = y + 1; i < y + 3; i++) {
			if (asema->lauta[x][i] == NULL) {
				lista.push_back(Siirto(*ruutu, Ruutu(x, i)));
			}
			else
				break;
		}
	}

	// musta rivillä 7
	if (y == 6 && lrv == 1) {
		for (int i = y - 1; i > y - 3; i--) {
			if (asema->lauta[x][i] == NULL) {
				lista.push_back(Siirto(*ruutu, Ruutu(x, i)));
			}
			else
				break;
		}
	}
	// perusruudut valkeille 
	if ((y == 2 || y == 3 || y == 4 || y == 5 || y == 6) && lrv == 0) {
		//siirtymät eteenpäin
		if (asema->lauta[x][y + 1] == NULL) {
			if (y < 6)
				lista.push_back(Siirto(*ruutu, Ruutu(x, y + 1)));
			else
				lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(x, y + 1)), lista, asema);
		}
		//syönnit viistoon
		if (x + 1 < 8) { 
			if (asema->lauta[x + 1][y + 1] != NULL) {
				trv = asema->lauta[x + 1][y + 1]->getVari();
				if (lrv == trv) {
				}
				if (lrv != trv) {
					if (y < 6)
						lista.push_back(Siirto(*ruutu, Ruutu(x + 1, y + 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(x + 1, y + 1)), lista, asema);
				}
			}
		}
		if (x - 1 >= 0) {
			if (asema->lauta[x - 1][y + 1] != NULL) {
				trv = asema->lauta[x - 1][y + 1]->getVari();
				if (lrv == trv) {
				}
				if (lrv != trv) {
					if (y < 6)
						lista.push_back(Siirto(*ruutu, Ruutu(x - 1, y + 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(x - 1, y + 1)), lista, asema);
				}
			}
		}
	}
	// perusruudut mustille 
	if ((y == 5 || y == 4 || y == 3 || y == 2 || y == 1) && lrv == 1) {
		//siirtymät eteenpäin
		if (asema->lauta[x][y - 1] == NULL) {
			if (y > 1)
				lista.push_back(Siirto(*ruutu, Ruutu(x, y - 1)));
			else
				lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(x, y - 1)), lista, asema);
		}
		//syönnit viistoon
		if (x + 1 < 8) { 
			if (asema->lauta[x + 1][y - 1] != NULL) {
				trv = asema->lauta[x + 1][y - 1]->getVari();
				if (lrv == trv) {
				}
				if (lrv != trv) {
					if (y > 1)
						lista.push_back(Siirto(*ruutu, Ruutu(x + 1, y - 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(x + 1, y - 1)), lista, asema);
				}
			}
		}
		if (x - 1 >= 0) {
			if (asema->lauta[x - 1][y - 1] != NULL) {
				trv = asema->lauta[x - 1][y - 1]->getVari();
				if (lrv == trv) {
				}
				if (lrv != trv) {
					if (y > 1)
						lista.push_back(Siirto(*ruutu, Ruutu(x - 1, y - 1)));
					else
						lisaaSotilaanKorotukset(&Siirto(*ruutu, Ruutu(x - 1, y - 1)), lista, asema);
				}
			}
		}
	}

	// Ohestalyönti
	if (asema->kaksoisaskelSarakkeella != -1){
		if (vari == 0 && y == 4){
			if (asema->lauta[asema->kaksoisaskelSarakkeella][4] && asema->lauta[asema->kaksoisaskelSarakkeella][4]->getKoodi() == MS)
				lista.push_back(Siirto(*ruutu, Ruutu(asema->kaksoisaskelSarakkeella, 5)));
		}
		if (vari == 1 && y == 3){
			if (asema->lauta[asema->kaksoisaskelSarakkeella][3] && asema->lauta[asema->kaksoisaskelSarakkeella][3]->getKoodi() == VS)
				lista.push_back(Siirto(*ruutu, Ruutu(asema->kaksoisaskelSarakkeella, 2)));
		}
	}
}


void Sotilas::lisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) {
	if (siirto->getLoppuruutu().getRivi() == 7) {
		// valkea korottaa
		siirto->miksikorotetaan = asema->vd;
		lista.push_back(*siirto);

		Siirto torniksi = *siirto;
		torniksi.miksikorotetaan = asema->vt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi.miksikorotetaan = asema->vl;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi.miksikorotetaan = asema->vr;
		lista.push_back(ratsuksi);
	}
	else if (siirto->getLoppuruutu().getRivi() == 0) {
		siirto->miksikorotetaan = asema->md;
		lista.push_back(*siirto);

		Siirto torniksi = *siirto;
		torniksi.miksikorotetaan = asema->mt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi.miksikorotetaan = asema->ml;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi.miksikorotetaan = asema->mr;
		lista.push_back(ratsuksi);
	}
}





