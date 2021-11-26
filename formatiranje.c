#include <stdio.h>
#include <string.h>
#include "formatiranje.h"
#include <stdlib.h>

void line(int sirina, char znak){
	for(int i = 0; i < sirina; i++) printf("%c", znak);
	printf("\n");
};

void up(char* naslov, char znak, int sirina){
	line(sirina, znak);
	printf("%s\n", naslov);
};

void middle(char* naslov, char znak, int sirina){
	printf("%s", naslov);
	line(sirina - strlen(naslov) + 1, znak);
};

void down(char* naslov, char znak, int sirina){
	printf("%s\n", naslov);
	line(sirina, znak);
};

void title(pozicija poz, char* naslov, char znak, int sirina ){
	poz(naslov, znak, sirina);
};


void bullet_point(char* tekst, int sirina, double znesek){
	int n = sirina - strlen(tekst) - 3;
	printf("%s:%*.2lf €\n", tekst, n, znesek);	

}	
