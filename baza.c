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
	char* sql = "CREATE TABLE IF NOT EXISTS Place(id int PRIMARY KEY, 'neto placa' double, 'delavni dnevi' int, 'oddelani dnevi' int, 'prva izmena (h)' int, 'druga izmena (h)' int);";

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

int db_select_all(sqlite3* db){

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


int db_insert(sqlite3* db, double neto, int delavni, int oddelani, int prva, int druga){

	sqlite3_stmt* stmt = NULL;
	char* sql = "INSERT INTO Place(id, 'neto placa', 'delavni dnevi', 'oddelani dnevi', 'prva izmena (h)', 'druga izmena (h)') VALUES(?1, ?2, ?3, ?4, ?5, ?6);";
	int r;
	
	r = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if(r != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}
	
	sqlite3_bind_int(stmt, 1, 1);
	sqlite3_bind_double(stmt, 2, neto);
	sqlite3_bind_int(stmt, 3, delavni);
	sqlite3_bind_int(stmt, 4, oddelani);
	sqlite3_bind_int(stmt, 5, prva);
	sqlite3_bind_int(stmt, 6, druga);

	r = sqlite3_step(stmt);	
	if(r != SQLITE_DONE){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}

	sqlite3_finalize(stmt);
	
	return 0;	
}


int db_delete(sqlite3* db, int id){

	sqlite3_stmt* stmt = NULL;
	char* sql = "DELETE FROM Place where id=?1;";
	int r;
	
	r = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if(r != SQLITE_OK){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}

	sqlite3_bind_int(stmt, 1, id);
	if(r == SQLITE_OK) printf("Vrstica z indeksom %d je izbrisana.\n", id);

	r = sqlite3_step(stmt);	
	if(r != SQLITE_DONE){
		printf("%s\n", sqlite3_errmsg(db));
		exit(-1);
	}

	sqlite3_finalize(stmt);
	
	return 0;	
}
