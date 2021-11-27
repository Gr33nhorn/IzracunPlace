typedef void (*h_poz)(char* naslov, int sirina);
typedef void (*pozicija)(char* naslov, h_poz h_poz, char znak, int sirina);

void line(int, char);
void up(char* naslov, char znak, int sirina);
void middle(char* naslov, char znak, int sirina);
void down(char* naslov, char znak, int sirina);
void up_n_down(char* naslov, h_poz hpoz, char znak, int sirina);
void title(pozicija poz, h_poz h_poz, char* naslov, char znak, int sirina );
void bullet_point(char* tekst, int sirina, double znesek);
void cumulative(char* tekst, int sirina, double znesek);
void l(char* naslov, int sirina);
void m(char* naslov, int sirina);
void r(char* naslov, int sirina);
