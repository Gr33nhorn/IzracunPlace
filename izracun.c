#include <stdio.h>
#include "formatiranje.h"




#define SIRINA 100
#define BP_ANIM  0
#define C_ANIM  1

#define M1 708.33f
#define S 291.67f
#define izhod_bruto 940.21f
#define DOPUST 6.565f
#define MINIMALNA 1024.24f
#define PRCNT_ZDRAV_ZAV1 0.0636f
#define PRCNT_POKOJNINSKO_ZAV1 0.155f
#define PRCNT_ZAPOSLOVANJE1 0.0014f
#define PRCNT_STAR_VARSTVO1 0.001f
#define PRCNT_IZMEN_DELO 0.1f
#define PRCNT_ZDRAV_ZAV2 0.0656f
#define PRCNT_POKOJNINSKO_ZAV2 0.0885f
#define PRCNT_ZAPOSLOVANJE2 0.003f
#define PRCNT_STAR_VARSTVO2 0.001F
#define PRCNT_POSKODBE_PRI_DELU 0.0053f
#define PRCNT_DAVEK2 0.221f

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

title(up_n_down, m,"PRISPEVKI IZ PLAČE", '-', SIRINA);

double zdrav_zavarovanje = PRCNT_ZDRAV_ZAV1 * prva_bruto;
bullet_point("ZDRAVSTVENO ZAVAROVANJE", SIRINA, zdrav_zavarovanje, BP_ANIM);

double pokojninsko_zavarovanje = PRCNT_POKOJNINSKO_ZAV1 * prva_bruto;
bullet_point("POKOJNINSKO ZAVAROVANJE", SIRINA, pokojninsko_zavarovanje, BP_ANIM);

double zaposlovanje = PRCNT_ZAPOSLOVANJE1 * prva_bruto;
bullet_point("ZAPOSLOVANJE", SIRINA, zaposlovanje, BP_ANIM);

double starsevsko_varstvo = PRCNT_STAR_VARSTVO1 * prva_bruto;
bullet_point("STARSEVSKO VARSTVO", SIRINA, starsevsko_varstvo, BP_ANIM);

double prispevki = zdrav_zavarovanje + pokojninsko_zavarovanje + zaposlovanje + starsevsko_varstvo;
double osnova_za_dohodnino = prva_bruto - prispevki - S;
double dohodnina = 0.16 * M1 + (osnova_za_dohodnino - M1) * 0.26;
bullet_point("DOHODNINA", SIRINA, dohodnina, BP_ANIM);

cumulative("SKUPAJ", SIRINA, prispevki, C_ANIM);

bullet_point("SKUPAJ Z DOHODNINO", SIRINA, dohodnina + prispevki, BP_ANIM);

//PLAČILA***************************************

printf("\n\n\n");

title(up_n_down, m, "PLAČILA", '-', SIRINA);

double za_prvo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_prva_izmena;
bullet_point("REDNO DELO I. IZMENA - IZHODISCE PO KP", SIRINA, za_prvo_izmeno, BP_ANIM);

double za_drugo_izmeno = (izhod_bruto * oddelani_dnevi / delovni_dnevi) / (ure_prva_izmena + ure_druga_izmena) * ure_druga_izmena;
bullet_point("REDNO DELO II. IZMENA - IZHODISCE PO KP", SIRINA, za_drugo_izmeno, BP_ANIM);

double letni_dopust = ure_dopust * DOPUST;
bullet_point("LETNI DOPUST", SIRINA, letni_dopust, BP_ANIM);

double razlika_do_minimalne = (MINIMALNA - izhod_bruto) * oddelani_dnevi / delovni_dnevi;
bullet_point("RAZLIKA DO MINIMALNE PLACE", SIRINA, razlika_do_minimalne, BP_ANIM);

double dodatek_za_izmensko = za_drugo_izmeno * PRCNT_IZMEN_DELO;
bullet_point("10% DODATEK - izmensko delo", SIRINA, dodatek_za_izmensko, BP_ANIM);

double delovna_uspesnost = prva_bruto - dodatek_za_izmensko - za_prvo_izmeno - za_drugo_izmeno - letni_dopust - razlika_do_minimalne;
bullet_point("DELOVNA USPESNOST", SIRINA, delovna_uspesnost, BP_ANIM);

cumulative("SKUPAJ", SIRINA, prva_bruto, C_ANIM);


//PRISPEVKI NA PLAČE********************************

printf("\n\n\n");

title(up_n_down, m, "PRISPEVKI NA PLAČE", '-', SIRINA);

double zdrav_zavarovanje_2 = PRCNT_ZDRAV_ZAV2 * prva_bruto;
bullet_point("ZDRAVSTVENO ZAVAROVANJE", SIRINA, zdrav_zavarovanje_2, BP_ANIM);

double pokojninsko_zavarovanje_2 = PRCNT_POKOJNINSKO_ZAV2 * prva_bruto;
bullet_point("POKOJNISNKO ZAVAROVANJE", SIRINA, pokojninsko_zavarovanje_2, BP_ANIM);

double zaposlovanje_2 = PRCNT_ZAPOSLOVANJE2 * prva_bruto;
bullet_point("ZAPOSLOVANJE", SIRINA, zaposlovanje_2, BP_ANIM);

double starsevsko_varstvo_2 = PRCNT_STAR_VARSTVO2 * prva_bruto;
bullet_point("STARSEVSKO VARSTVO", SIRINA, starsevsko_varstvo_2, BP_ANIM);

double poskodbe_pri_delu = PRCNT_POSKODBE_PRI_DELU * prva_bruto;
bullet_point("POSKODBE PRI DELU", SIRINA, poskodbe_pri_delu, BP_ANIM);

cumulative("SKUPAJ", SIRINA, prva_bruto * PRCNT_DAVEK2, C_ANIM);


/*for(int i = 0; i < 100000000; i++) {
	printf("\r%d%*s",i, 10, "jajca");
	fflush(stdout);}*/



return 0;}
