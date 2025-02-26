#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

Table* create_table(int rows, int cols) {
    Table *t = malloc(sizeof(Table));
    t->rows = rows;
    t->cols = cols;

    t->data = malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; i++) {
        t->data[i] = malloc(cols * sizeof(char *));
        for (int j = 0; j < cols; j++) {
            t->data[i][j] = NULL;
        }
    }
    return t;
}

void set_cell(Table *t, int row, int col, const char *value) {
    if (row >= t->rows || col >= t->cols) return;
    t->data[row][col] = malloc(strlen(value) + 1);
    strcpy(t->data[row][col], value);
}

void print_table(Table *t) {
    int col_width = 10;

    printf("+");
    for (int j = 0; j < t->cols; j++) {
        for (int k = 0; k < col_width; k++) printf("-");
        printf("+");
    }
    printf("\n");

    for (int i = 0; i < t->rows; i++) {
        printf("|");
        for (int j = 0; j < t->cols; j++) {
            if (t->data[i][j] != NULL)
                printf(" %-8s |", t->data[i][j]);
            else
                printf("          |");
        }
        printf("\n");

        printf("+");
        for (int j = 0; j < t->cols; j++) {
            for (int k = 0; k < col_width; k++) printf("-");
            printf("+");
        }
        printf("\n");
    }
}

void free_table(Table *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            if (t->data[i][j] != NULL)
                free(t->data[i][j]);
        }
        free(t->data[i]);
    }
    free(t->data);
    free(t);
}
