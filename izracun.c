#include <stdio.h>
#include "formatiranje.h"
#include <math.h>
#include <string.h>

#define M1 708.33f
#define S 291.67f
#define izhod_bruto 940.21f
#define DOPUST 6.565f
#define MINIMALNA 1024.24f
#define SIRINA 100



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

printf("\n\n\n");

title(up_n_down, r,"PRISPEVKI IZ PLAČE", '-', SIRINA);

double zdrav_zavarovanje = 0.0636 * prva_bruto;
bullet_point("ZDRAVSTVENO ZAVAROVANJE", SIRINA, zdrav_zavarovanje);

double pokojninsko_zavarovanje = 0.155 * prva_bruto;
bullet_point("POKOJNINSKO ZAVAROVANJE", SIRINA, pokojninsko_zavarovanje);

double zaposlovanje = 0.0014 * prva_bruto;
bullet_point("ZAPOSLOVANJE", SIRINA, zaposlovanje);

double starsevsko_varstvo = 0.001 * prva_bruto;
bullet_point("STARSEVSKO VARSTVO", SIRINA, starsevsko_varstvo);

double prispevki = zdrav_zavarovanje + pokojninsko_zavarovanje + zaposlovanje + starsevsko_varstvo;
bullet_point("PRISPEVKI", SIRINA, prispevki);

double osnova_za_dohodnino = prva_bruto - prispevki - S;
bullet_point("OSNOVNA ZA DOHODNINO", SIRINA, osnova_za_dohodnino);

double dohodnina = 0.16 * M1 + (osnova_za_dohodnino - M1) * 0.26;
bullet_point("DOHODNINA", SIRINA, dohodnina);

cumulative("SKUPAJ", SIRINA, prispevki);

bullet_point("SKUPAJ Z DOHODNINO", SIRINA, dohodnina + prispevki);

//PLAČILA***************************************

printf("\n\n\n");

title(up_n_down, m, "PLAČILA", '-', SIRINA);

double za_prvo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_prva_izmena;
bullet_point("REDNO DELO I. IZMENA - IZHODISCE PO KP", SIRINA, za_prvo_izmeno);

double za_drugo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_druga_izmena;
bullet_point("REDNO DELO II. IZMENA - IZHODISCE PO KP", SIRINA, za_drugo_izmeno);

double letni_dopust = ure_dopust * DOPUST;
bullet_point("LETNI DOPUST", SIRINA, letni_dopust);

double razlika_do_minimalne = (MINIMALNA - izhod_bruto) * oddelani_dnevi / delovni_dnevi;
bullet_point("RAZLIKA DO MINIMALNE PLACE", SIRINA, razlika_do_minimalne);

double dodatek_za_izmensko = za_drugo_izmeno * 0.1;
bullet_point("10% DODATEK - izmensko delo", SIRINA, dodatek_za_izmensko);

double delovna_uspesnost = prva_bruto - dodatek_za_izmensko - za_prvo_izmeno - za_drugo_izmeno - letni_dopust - razlika_do_minimalne;
bullet_point("DELOVNA USPESNOST", SIRINA, delovna_uspesnost);

cumulative("SKUPAJ", SIRINA, prva_bruto);

//PRISPEVKI NA PLAČE********************************

printf("\n\n\n");

title(up_n_down, l, "PRISPEVKI NA PLAČE", '-', SIRINA);

double zdrav_zavarovanje_2 = 0.0656 * prva_bruto;
bullet_point("ZDRAVSTVENO ZAVAROVANJE", SIRINA, zdrav_zavarovanje_2);

double pokojninsko_zavarovanje_2 = 0.0885 * prva_bruto;
bullet_point("POKOJNISNKO ZAVAROVANJE", SIRINA, pokojninsko_zavarovanje_2);

double zaposlovanje_2 = 0.003 * prva_bruto;
bullet_point("ZAPOSLOVANJE", SIRINA, zaposlovanje_2);

double starsevsko_varstvo_2 = 0.001 * prva_bruto;
bullet_point("STARSEVSKO VARSTVO", SIRINA, starsevsko_varstvo_2);

double poskodbe_pri_delu = 0.0053 * prva_bruto;
bullet_point("POSKODBE PRI DELU", SIRINA, poskodbe_pri_delu);

cumulative("SKUPAJ", SIRINA, prva_bruto * 0.221);


int sirina = 100;
printf("%*s\n", (int)sirina/2, "TEST");

return 0;}
