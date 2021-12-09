int open_db(sqlite3** db, char* db_ime);
int db_insert(sqlite3* db, double neto, int delavni, int oddelani, int prva, int druga);
int db_select_all(sqlite3* db);
int db_delete(sqlite3* db, int id);
