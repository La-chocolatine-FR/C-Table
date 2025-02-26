#ifndef TABLE_H
#define TABLE_H

typedef struct {
    int rows;
    int cols;
    char ***data;
} Table;

Table* create_table(int rows, int cols);
void set_cell(Table *t, int row, int col, const char *value);
void print_table(Table *t);
void free_table(Table *t);

#endif
