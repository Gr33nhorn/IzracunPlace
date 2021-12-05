int open_db(sqlite3** db, char* db_ime);
int insert(sqlite3* db, int indx, char* vrsta_zneska, double znesek);
int select_all(sqlite3* db);
