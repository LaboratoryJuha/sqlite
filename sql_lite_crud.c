#include <sql_lite_example.h>
#include <stdio.h>

sqlite3 *db = NULL;
sqlite3_stmt *stmt = NULL;
int return_code = 0;

void sql_lite_create() {
    char *sql_create_table = NULL;

    return_code = sqlite3_open_v2("./example.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if (return_code != SQLITE_OK) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    sql_create_table = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT);";

    return_code = sqlite3_exec(db, sql_create_table, 0, 0, 0);
}

void sql_lite_read() {
    printf("Read operation\n");
    // Implementation of read operation
}

void sql_lite_update() {
    printf("Update operation\n");
    // Implementation of update operation
}

void sql_lite_delete() {
    printf("Delete operation\n");
    // Implementation of delete operation
}