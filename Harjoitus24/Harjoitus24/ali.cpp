#include "maarittely.h"
int Valikko()
{
	int valinta;
	cout << "VALIKKO" << endl << "0 Lopeta" << endl << "1 Lisaa henkilo" << endl << "2 Nayta henkilo" << endl << "3 Nayta kaikki henkilot" << endl << "4 Poista henkilo" << endl << "5 Tallenna" << endl << "6 Hae tiedostosta" << endl;
	cin >> valinta;
	return valinta;
}

void TulostaHenkilo(HKL henkilo)
{
	cout << endl;
	cout << henkilo.etunimi << " " << henkilo.matka << " " << henkilo.hattu << endl;
	cout << endl;
}

void TulostaKaikkiHenkilot(HKL henkilo[], int lkm)
{
	cout << endl;
	for (int i = 0; i < lkm; i++)
	{
		cout << henkilo[i].etunimi << " " << henkilo[i].matka << " " << henkilo[i].hattu << endl;
	}
	cout << endl;
}

void LisaaHenkilo(HKL henkilo[], int *lkm)
{
	(*lkm)++;
	cout << "Etunimi: "; cin >> henkilo[(*lkm) - 1].etunimi;
	cout << "Koulumatka: "; cin >> henkilo[(*lkm) - 1].matka;
	cout << "Hatun koko: "; cin >> henkilo[(*lkm) - 1].hattu;
}

void PoistaHenkilo(HKL henkilo[], int *lkm)
{
	if (*lkm > 0)
	{
		(*lkm)--;
		henkilo[*lkm].etunimi[0] = '\0';
	}
	else
		cout << "Ei henkiloita tietokannassa." << endl;
}

void Tallenna(HKL henkilo[], int lkm)
{
	ofstream tdsto("teksti.txt");
	for (int i = 0; i < lkm; i++)
	{
		tdsto << henkilo[i].etunimi << " " << henkilo[i].matka << " " << henkilo[i].hattu << endl;
	}
	tdsto.close();
}

void HaeTiedot(HKL henkilo[], int *lkm)
{
	ifstream syotto("teksti.txt");
	if (syotto.is_open())
	{
		while (syotto.peek() != EOF)
		{		
			(*lkm)++;
			syotto.getline(henkilo[(*lkm) - 1].etunimi, 20, ' ');
			syotto >> henkilo[(*lkm) - 1].matka;
			syotto >> henkilo[(*lkm) - 1].hattu;
			syotto.get();
		}
	}
	syotto.close();
}