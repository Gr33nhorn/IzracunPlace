#include <stdio.h>
#include "formatiranje.h"
#include <sqlite3.h>
#include "baza.h"
#include <time.h>
#include "racuni.h"

#define SIRINA 60
#define BP_ANIM  0
#define C_ANIM  0

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
prva_bruto = bruto_placa_1(950.0, S, M1);


//PRISPEVKI IZ PLAČE*****************************

printf("\n\n\n");

title(up_n_down, m,"PRISPEVKI IZ PLAČE", '-', SIRINA);

double zdrav_zavarovanje = zdravstveno_zavarovanje(prva_bruto, PRCNT_ZDRAV_ZAV1);
bullet_point("ZDRAVSTVENO ZAVAROVANJE", SIRINA, zdrav_zavarovanje, BP_ANIM);

double pokojninsko_zavarovanje = pok_zavarovanje(prva_bruto, PRCNT_POKOJNINSKO_ZAV1);
bullet_point("POKOJNINSKO ZAVAROVANJE", SIRINA, pokojninsko_zavarovanje, BP_ANIM);

double zaposlovanje = f_zaposlovanje(prva_bruto, PRCNT_ZAPOSLOVANJE1);
bullet_point("ZAPOSLOVANJE", SIRINA, zaposlovanje, BP_ANIM);

double starsevsko_varstvo = star_varstvo(prva_bruto, PRCNT_STAR_VARSTVO1);
bullet_point("STARSEVSKO VARSTVO", SIRINA, starsevsko_varstvo, BP_ANIM);

double prispevki = zdrav_zavarovanje + pokojninsko_zavarovanje + zaposlovanje + starsevsko_varstvo;
double osnova_za_dohodnino = osnova_dohodnina(prva_bruto, prispevki, S);
double dohodnina = f_dohodnina(osnova_za_dohodnino, M1);
bullet_point("DOHODNINA", SIRINA, dohodnina, BP_ANIM);

cumulative("SKUPAJ", SIRINA, prispevki, C_ANIM);

bullet_point("SKUPAJ Z DOHODNINO", SIRINA, dohodnina + prispevki, BP_ANIM);

//PLAČILA***************************************

printf("\n\n\n");

title(up_n_down, m, "PLAČILA", '-', SIRINA);

double za_prvo_izmeno = izmena(izhod_bruto , oddelani_dnevi, delovni_dnevi, ure_prva_izmena, ure_druga_izmena);
bullet_point("REDNO DELO I. IZMENA - IZHODISCE PO KP", SIRINA, za_prvo_izmeno, BP_ANIM);

double za_drugo_izmeno = izmena(izhod_bruto , oddelani_dnevi, delovni_dnevi, ure_druga_izmena, ure_prva_izmena);
bullet_point("REDNO DELO II. IZMENA - IZHODISCE PO KP", SIRINA, za_drugo_izmeno, BP_ANIM);

double letni_dopust = let_dopust(ure_dopust, DOPUST);
bullet_point("LETNI DOPUST", SIRINA, letni_dopust, BP_ANIM);

double razlika_do_minimalne = dif_do_minimalne(izhod_bruto, oddelani_dnevi, delovni_dnevi, MINIMALNA);
bullet_point("RAZLIKA DO MINIMALNE PLACE", SIRINA, razlika_do_minimalne, BP_ANIM);

double dodatek_za_izmensko = dod_pop_izmena(za_drugo_izmeno, PRCNT_IZMEN_DELO);
bullet_point("10% DODATEK - izmensko delo", SIRINA, dodatek_za_izmensko, BP_ANIM);

double delovna_uspesnost = uspesnost(prva_bruto, dodatek_za_izmensko, za_prvo_izmeno, za_drugo_izmeno, letni_dopust, razlika_do_minimalne);
bullet_point("DELOVNA USPESNOST", SIRINA, delovna_uspesnost, BP_ANIM);

cumulative("SKUPAJ", SIRINA, prva_bruto, C_ANIM);


//PRISPEVKI NA PLAČE********************************

printf("\n\n\n");

title(up_n_down, m, "PRISPEVKI NA PLAČE", '-', SIRINA);

double zdrav_zavarovanje_2 = zdravstveno_zavarovanje(prva_bruto, PRCNT_ZDRAV_ZAV2);
bullet_point("ZDRAVSTVENO ZAVAROVANJE", SIRINA, zdrav_zavarovanje_2, BP_ANIM);

double pokojninsko_zavarovanje_2 = pok_zavarovanje(prva_bruto, PRCNT_POKOJNINSKO_ZAV2);
bullet_point("POKOJNISNKO ZAVAROVANJE", SIRINA, pokojninsko_zavarovanje_2, BP_ANIM);

double zaposlovanje_2 = f_zaposlovanje(prva_bruto, PRCNT_ZAPOSLOVANJE2);
bullet_point("ZAPOSLOVANJE", SIRINA, zaposlovanje_2, BP_ANIM);

double starsevsko_varstvo_2 = star_varstvo(prva_bruto, PRCNT_STAR_VARSTVO2);
bullet_point("STARSEVSKO VARSTVO", SIRINA, starsevsko_varstvo_2, BP_ANIM);

double poskodbe_pri_delu = poskodbe(prva_bruto, PRCNT_POSKODBE_PRI_DELU);
bullet_point("POSKODBE PRI DELU", SIRINA, poskodbe_pri_delu, BP_ANIM);

cumulative("SKUPAJ", SIRINA, prva_bruto * PRCNT_DAVEK2, C_ANIM);

sqlite3* db;
open_db(&db, "Place.db");
//db_insert(db, neto, delovni_dnevi, oddelani_dnevi, ure_prva_izmena, ure_druga_izmena);
db_delete(db, 1);
db_select_all(db);

return 0;}
