typedef void (*pozicija)(char* naslov, char znak, int sirina);
void line(int, char);
void up(char* naslov, char znak, int sirina);
void middle(char* naslov, char znak, int sirina);
void down(char* naslov, char znak, int sirina);
void title(pozicija poz, char* naslov, char znak, int sirina );
void bullet_point(char* tekst, int sirina, double znesek);
