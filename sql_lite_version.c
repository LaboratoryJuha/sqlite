#include <sql_lite_example.h>
#include <stdio.h>
#include <stdlib.h>

void print_sqlite_version() {
    unsigned char *version = NULL;
    sqlite3 *db = NULL;
    sqlite3_stmt *statment = NULL;
    int return_code = 0;

{   // Get the SQLite library version
    version = (unsigned char *)sqlite3_libversion();
    printf("SQLite version: %s\n", version);
}

{   // Get the SQLite library version in db
    return_code = sqlite3_open(":memory:", &db);
    if (return_code != SQLITE_OK) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    return_code = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION();", -1, &statment, NULL);
    if (return_code != SQLITE_OK) {
        printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    return_code = sqlite3_step(statment);
    if(return_code == SQLITE_ROW) {
        version = (unsigned char *)sqlite3_column_text(statment, 0);
        printf("SQLite version from DB: %s\n", version);
    } else {
        printf("Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(statment);
    sqlite3_close(db);
}
}