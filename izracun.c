#include <stdio.h>
#include "formatiranje.h"

#define M1 708.33f
#define S 291.67f
#define izhod_bruto 940.21f
#define DOPUST 6.565f
#define MINIMALNA 1024.24f
#define SIRINA 50



int main(void){




printf("\n");
double neto;
printf("Neto plača (€): ");
scanf("%lf", &neto);

int delovni_dnevi;
printf("Število vseh delovnih dni v mesecu: ");
scanf("%d", &delovni_dnevi);

int oddelani_dnevi;
printf("Število oddelanih dni v mesecu: ");
scanf("%d", &oddelani_dnevi);

int ure_prva_izmena;
printf("Oddelane ure prva izmena: ");
scanf("%d", &ure_prva_izmena);

int ure_druga_izmena;
printf("Oddelane ure druga izmena: ");
scanf("%d", &ure_druga_izmena);

int ure_dopust;
printf("Ure dopusta: ");
scanf("%d", &ure_dopust);

double prva_bruto;
prva_bruto = (neto - 0.1 * M1 -0.26 * S) / (-0.26 * 0.779 - 0.221 + 1);

//PRISPEVKI IZ PLAČE*****************************
double zdrav_zavarovanje = 0.0636 * prva_bruto;
double pokojninsko_zavarovanje = 0.155 * prva_bruto;
double zaposlovanje = 0.0014 * prva_bruto;
double starsevsko_varstvo = 0.001 * prva_bruto;
double prispevki = zdrav_zavarovanje + pokojninsko_zavarovanje + zaposlovanje + starsevsko_varstvo;
double osnova_za_dohodnino = prva_bruto - prispevki - S;
double dohodnina = 0.16 * M1 + (osnova_za_dohodnino - M1) * 0.26;

printf("\n\n");
title(down, "PRISPEVKI IZ PLAČE", '_', 50);
printf("ZDRAVSTVENO ZAVAROVANJE:%24.2lf €\n", zdrav_zavarovanje);
printf("POKOJNINSKO ZAVAROVANJE:%24.2lf €\n", pokojninsko_zavarovanje);
printf("ZAPOSLOVANJE:%35.2lf €\n", zaposlovanje);
printf("STARŠEVSKO VARSTVO:%29.2lf €\n", starsevsko_varstvo);
printf("DOHODNINA:%38.2lf €\n", dohodnina);
line(SIRINA, '_');
printf("SKUPAJ:%41.2lf €\n", prispevki);
printf("SKUPAJ Z DOHODNINO:%29.2lf €\n", dohodnina + prispevki);
line(SIRINA, '_');
//printf("osnova_za_dohodnino:%.2lf €\n", osnova_za_dohodnino);


//PLAČILA***************************************
printf("\n\n");

title(down, "PLAČILA", '_', 50);
double za_prvo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_prva_izmena;
printf("REDNO DELO I. IZMENA - IZHODIŠČE PO KP:%9.2f €\n", za_prvo_izmeno);

double za_drugo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_druga_izmena;
printf("REDNO DELO II. IZMENA - IZHODIŠČE PO KP:%8.2f €\n", za_drugo_izmeno);

double letni_dopust = ure_dopust * DOPUST;
printf("LETNI DOPUST:%35.2lf €\n", letni_dopust);

double razlika_do_minimalne = (MINIMALNA - izhod_bruto) * oddelani_dnevi / delovni_dnevi;
printf("RAZLIKA DO MINIMALNE PLAČE:%21.2lf €\n", razlika_do_minimalne);

double dodatek_za_izmensko = za_drugo_izmeno * 0.1;
printf("10%% DODATEK - izmensko delo:%20.2lf €\n", dodatek_za_izmensko);
double delovna_uspesnost = prva_bruto - dodatek_za_izmensko - za_prvo_izmeno - za_drugo_izmeno - letni_dopust - razlika_do_minimalne;
printf("DELOVNA USPEŠNOST - znesek:%21.2lf €\n", delovna_uspesnost);

line(SIRINA, '_');
printf("SKUPAJ:%41.2lf €\n", prva_bruto);
line(SIRINA, '_');

//PRISPEVKI NA PLAČE********************************
printf("\n\n");
title(down, "PRISPEVKI NA PLAČE", '_', 50);

double zdrav_zavarovanje_2 = 0.0656 * prva_bruto;
printf("ZDRAVSTVENO ZAVAROVANJE:%24.2lf €\n", zdrav_zavarovanje_2);

double pokojninsko_zavarovanje_2 = 0.0885 * prva_bruto;
printf("POKOJNINSKO ZAVAROVANJE:%24.2lf €\n", pokojninsko_zavarovanje_2);

double zaposlovanje_2 = 0.003 * prva_bruto;
printf("ZAPOSLOVANJE:%35.2lf €\n", zaposlovanje_2);

double starsevsko_varstvo_2 = 0.001 * prva_bruto;
printf("STARŠEVSKO VARSTVO:%29.2lf €\n", starsevsko_varstvo_2);

double poskodbe_pri_delu = 0.0053 * prva_bruto;
printf("POŠKODBE PRI DELU:%30.2lf €\n", poskodbe_pri_delu);

line(SIRINA, '_');
printf("SKUPAJ:%41.2lf €\n", 0.1634 * prva_bruto);
line(SIRINA, '_');
return 0;}
