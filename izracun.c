#include <stdio.h>

#define M1 708.33f
#define S 291.67f
#define izhod_bruto 940.21f
#define DOPUST 6.56f
#define MINIMALNA 1024.24f

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
printf("%.2lf €\n", prva_bruto);

double zdrav_zavarovanje = 0.0636 * prva_bruto;
double pokojninsko_zavarovanje = 0.155 * prva_bruto;
double zaposlovanje = 0.0014 * prva_bruto;
double starsevsko_varstvo = 0.001 * prva_bruto;
double prispevki = zdrav_zavarovanje + pokojninsko_zavarovanje + zaposlovanje + starsevsko_varstvo;
double osnova_za_dohodnino = prva_bruto - prispevki - S;
double dohodnina = 0.16 * M1 + (osnova_za_dohodnino - M1) * 0.26;

printf("zdrav_zavarovanje: %.2lf €\n", zdrav_zavarovanje);
printf("pokojnisnko_zavarovanje: %.2lf €\n", pokojninsko_zavarovanje);
printf("zaposlovanje: %.2lf €\n", zaposlovanje);
printf("starsevsko_varstvo: %.2lf €\n", starsevsko_varstvo);
printf("prispevki: %.2lf €\n", prispevki);
printf("osnova_za_dohodnino: %.2lf €\n", osnova_za_dohodnino);
printf("dohodnina: %.2lf €\n", dohodnina);

printf("\n");
double za_prvo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_prva_izmena;
printf("REDNO DELO I. IZMENA - IZHODIŠČE PO KP %.2f €\n", za_prvo_izmeno);
double za_drugo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_druga_izmena;
printf("REDNO DELO II. IZMENA - IZHODIŠČE PO KP %.2f €\n", za_drugo_izmeno);
double letni_dopust = ure_dopust * DOPUST;
printf("LETNI DOPUST: %.2lf €\n", letni_dopust);
double razlika_do_minimalne = MINIMALNA - izhod_bruto * oddelani_dnevi / delovni_dnevi;
printf("RAZLIKA DO MINIMALNE PLAČE %.2lf €\n", razlika_do_minimalne);
double dodatek_za_izmensko = za_drugo_izmeno * 0.1;
printf("10%% DODATEK - izmensko delo : %.2lf€\n", dodatek_za_izmensko);



return 0;}
