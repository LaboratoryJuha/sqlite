#include "sql_lite_example.h"

int main() {
    print_sqlite_version();

    sql_lite_create();
    sql_lite_read();
    sql_lite_update();
    sql_lite_delete();
    return 0;
}