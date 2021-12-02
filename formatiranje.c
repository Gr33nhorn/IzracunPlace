#include <stdio.h>
#include <string.h>
#include "formatiranje.h"
#include <stdlib.h>
#include <unistd.h>

void line(int sirina, char znak){
	FILE* file = fopen("izracun.txt", "a");
	for(int i = 0; i < sirina; i++){
		printf("%c", znak);
		fprintf(file, "%c", znak);
	}
	printf("\n");
	fprintf(file, "\n");
	fclose(file);
};


void l(char* naslov, int sirina){
	FILE* file = fopen("izracun.txt", "a");
	fprintf(file, "%s\n", naslov);			
	printf("%s\n", naslov);
	fclose(file);
	
};

			
void m(char* naslov, int sirina){
	printf("%*s\n", (int)(sirina + strlen(naslov))/2, naslov);
	FILE* file = fopen("izracun.txt", "a");
	fprintf(file, "%*s\n", (int)(sirina + strlen(naslov))/2, naslov);
	fclose(file);
};


void r(char* naslov, int sirina){
	printf("%*s\n", sirina + 1, naslov);
	FILE* file = fopen("izracun.txt", "a");
	fprintf(file, "%*s\n", sirina + 1, naslov);
	fclose(file);
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

};


void down(char* naslov, h_poz h_poz, char znak, int sirina){
	h_poz(naslov, sirina);
	line(sirina, znak);
};


void title(pozicija poz, h_poz h_poz, char* naslov, char znak, int sirina ){
	poz(naslov, h_poz, znak, sirina);
};


void bullet_point(char* tekst, int sirina, double znesek, int anim){
	int n = sirina - strlen(tekst) - 3;
	double p = znesek/1000.0;
	double x;
	while(x < (znesek - p) && anim){
		printf("%s:%*.2lf €\r", tekst, n, x += p);
		fflush(stdout);
		usleep(900);
		}
	if(anim) usleep(500);	
	printf("%s:%*.2lf €\n", tekst, n, znesek);
	FILE* file = fopen("izracun.txt", "a");
	fprintf(file, "%s:%*.2lf €\n", tekst, n, znesek);
	fclose(file);

}	

void cumulative(char* tekst, int sirina, double znesek, int anim){
	line(sirina, '_');
	bullet_point(tekst, sirina, znesek, anim);
}


