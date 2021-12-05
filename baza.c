#include <sqlite3.h>
#include <stdlib.h>
#include <stdio.h>



int open_db(sqlite3** db, char* db_ime){

	if( sqlite3_initialize() != SQLITE_OK )
		exit(-1);
	
	int r;		
	char* ime = db_ime;
	
	
	r = sqlite3_open_v2(ime, db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL );

	if( r != SQLITE_OK ){
		printf("%s\n", sqlite3_errmsg(*db));
		sqlite3_close(*db);
		exit(-1);
	}	
		
	sqlite3_stmt* stmt = NULL;
	char* sql = "CREATE TABLE IF NOT EXISTS Place(id int UNIQUE, ime text, znesek float)";

	r = sqlite3_prepare_v2(*db, sql, -1, &stmt, NULL);
	if(r != SQLITE_OK){
	printf("%s\n", sqlite3_errmsg(*db));
	exit(-1);
	}

	r = sqlite3_step(stmt);	
	if(r != SQLITE_DONE){
		printf("%s\n", sqlite3_errmsg(*db));
		exit(-1);
	}
	
	sqlite3_finalize(stmt);
	
	return 0;
}



int insert(sqlite3* db, int indx, char* vrsta_zneska, double znesek){

	sqlite3_stmt* stmt = NULL;
	char* sql = "INSERT INTO Place (id, ime, znesek) VALUES(?1, ?2, ?3)";
	int r;
	
	r = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if(r != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}

	int idx;
	int txt;
	int dbl;

	idx = sqlite3_bind_int(stmt, 1, indx);
	txt = sqlite3_bind_text(stmt, 2, vrsta_zneska, -1, NULL);
	dbl = sqlite3_bind_int(stmt, 3, znesek);

	if(txt != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}
	r = sqlite3_step(stmt);	
	if(r != SQLITE_DONE){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}

	sqlite3_finalize(stmt);
	
	return 0;
}


int select_all(sqlite3* db){

	sqlite3_stmt* stmt = NULL;
	char* sql = "SELECT * FROM Place";

	int r = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

	if(r != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}
	while(sqlite3_step(stmt) != SQLITE_DONE){
		const char* data;
		for(int i = 0; i < sqlite3_column_count(stmt); i++){
		data = (const char*)sqlite3_column_text(stmt, i);
		printf("%s: %s\n",sqlite3_column_name(stmt, i), data ? data : "[NULL]");
		}

	}
	sqlite3_finalize(stmt);
	return 0;
}
