#include <stdio.h>
#include "table.h"

int main() {
    Table *t = create_table(3, 3);

    set_cell(t, 0, 0, "ID");
    set_cell(t, 0, 1, "Nom");
    set_cell(t, 0, 2, "Age");

    set_cell(t, 1, 0, "1");
    set_cell(t, 1, 1, "Alice");
    set_cell(t, 1, 2, "23");

    set_cell(t, 2, 0, "2");
    set_cell(t, 2, 1, "Bob");
    set_cell(t, 2, 2, "30");

    print_table(t);
    free_table(t);

    return 0;
}
