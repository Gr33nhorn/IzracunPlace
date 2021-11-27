#include <stdio.h>
#include <string.h>
#include "formatiranje.h"
#include <stdlib.h>


void line(int sirina, char znak){
	for(int i = 0; i < sirina; i++) printf("%c", znak);
	printf("\n");
};


void l(char* naslov, int sirina){
			printf("%s\n", naslov);
			};

			
void m(char* naslov, int sirina){
			printf("%*s\n", (int)(sirina + strlen(naslov))/2, naslov);
};


void r(char* naslov, int sirina){
			printf("%*s\n", sirina + 1, naslov);
};


void up_n_down(char* naslov, h_poz h_poz, char znak, int sirina){
	
	line(sirina, znak);
	h_poz(naslov, sirina);
	line(sirina, znak);
};


void up(char* naslov, h_poz h_poz, char znak, int sirina){
	line(sirina, znak);
	h_poz(naslov, sirina);
};


void middle(char* naslov, h_poz h_poz, char znak, int sirina){
	if(h_poz == m){
		for(int i = 0; i < (sirina - strlen(naslov))/2; i++) printf("%c", znak);
			printf("%s", naslov);
		for(int i = 0; i < (sirina - strlen(naslov))/2 + 2; i++) printf("%c", znak);
		printf("\n");
		}
	if(h_poz == r){
		for(int i = 0; i < (sirina - strlen(naslov) + 1); i++) printf("%c", znak);
			printf("%s", naslov);
			printf("\n");}
			
	if(h_poz == l){
		printf("%s", naslov);
		for(int i = 0; i < (sirina - strlen(naslov) + 1); i++) printf("%c", znak);
		printf("\n");
		}
		
	//for(int i = 0; i < (sirina - strlen(naslov))/2; i++) printf("%c", znak);
};


void down(char* naslov, h_poz h_poz, char znak, int sirina){
	h_poz(naslov, sirina);
	line(sirina, znak);
};


void title(pozicija poz, h_poz h_poz, char* naslov, char znak, int sirina ){
	poz(naslov, h_poz, znak, sirina);
};


void bullet_point(char* tekst, int sirina, double znesek){
	int n = sirina - strlen(tekst) - 3;
	printf("%s:%*.2lf €\n", tekst, n, znesek);	

}	

void cumulative(char* tekst, int sirina, double znesek){
	line(sirina, '_');
	bullet_point(tekst, sirina, znesek);
}
