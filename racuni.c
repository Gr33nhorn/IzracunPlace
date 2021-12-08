double bruto_placa_1(double neto, double S, double M1){
	return (neto - 0.1 * M1 -0.26 * S) / (-0.26 * 0.779 - 0.221 + 1);
}

double zdravstveno_zavarovanje(double bruto, double procent){
	return procent * bruto;
}

double pok_zavarovanje(double bruto, double procent){
	return bruto * procent;
}

double f_zaposlovanje(double bruto, double procent){
	return procent * bruto;
}

double star_varstvo(double bruto, double procent){
	return procent * bruto;
}

double osnova_dohodnina(double bruto, double prispevki, double S){
	return bruto - prispevki - S;
}

double f_dohodnina(double osnova, double M1){
	return 0.16 * M1 + (osnova - M1) * 0.26;
}

double izmena(double iz_bruto, double oddelani, double delavni, double ure_prva, double ure_druga){
	return (iz_bruto * oddelani / delavni )/ (ure_prva + ure_druga) * ure_prva;
}

double let_dopust(double ure, double dopust){
	return ure * dopust;
}

double dif_do_minimalne(double iz_bruto, double oddelani, double delavni, double min){
	return (min - iz_bruto) * oddelani/ delavni;
}

double dod_pop_izmena(double za_drugo, double procent){
	return za_drugo * procent;
}

double uspesnost(double bruto, double izmen_dodatek, double prva, double druga, double dopust, double dif_min){
	return bruto - izmen_dodatek - prva - druga - dopust - dif_min;
}

double poskodbe(double bruto, double poskodbe_pri_delu){
	return poskodbe_pri_delu * bruto;
}

