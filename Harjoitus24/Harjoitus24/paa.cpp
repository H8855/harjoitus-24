#include "maarittely.h"
void main()
{
	int valinta = 1, lkm = 2, i = 0;
	HKL henkilo[10] = { { "Matti", 12.5, 23 }, { "Mikko", 43.6, 12 } };

	while (valinta != 0)
	{
		valinta = Valikko();
		switch (valinta)
		{
		case 0: valinta = 0; break;
		case 1: LisaaHenkilo(henkilo, &lkm); break;
		case 2: TulostaHenkilo(henkilo[lkm - 1]); break;
		case 3: TulostaKaikkiHenkilot(henkilo, lkm); break;
		case 4: PoistaHenkilo(henkilo, &lkm); break;
		case 5: Tallenna(henkilo, lkm); break;
		case 6: HaeTiedot(henkilo, &lkm); break;
		}
	}
}
