#include <stdio.h>
#include <stdlib.h>
#include "map.h"

Map* create_map(int rows, int cols) {
    Map* map = malloc(sizeof(Map));
    if (map == NULL) {
        // Hibakezelés, ha a memóriaallokáció nem sikerült
        return NULL;
    }

    map->rows = rows;
    map->cols = cols;

    map->data = malloc(rows * sizeof(char*));
    if (map->data == NULL) {
        free(map);  // Felszabadítjuk a már lefoglalt memóriát
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        map->data[i] = malloc(cols * sizeof(char));
        if (map->data[i] == NULL) {
            // Ha valami nem sikerült, felszabadítjuk a már lefoglalt memóriát
            for (int j = 0; j < i; j++) {
                free(map->data[j]);
            }
            free(map->data);
            free(map);
            return NULL;
        }
    }

    return map;
}

void map_initialization(Map* map, char value, char value2) {
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            // Ha a cella a térkép szélén van, akkor value2-t kap
            if (i == 0 || i == map->rows - 1 || j == 0 || j == map->cols - 1) {
                map->data[i][j] = value2;
            } else {
                map->data[i][j] = value;
            }
        }
    }
}


void set_value(Map* map, int x, int y, char value) {
    if (x >= 0 && x < map->rows && y >= 0 && y < map->cols) {
        map->data[x][y] = value;
    } else {
        // Hibakezelés, ha a koordináták érvénytelenek
        printf("Hiba: Ervenytelen koordinatak (%d, %d)\n", x, y);
    }
}

char get_value(Map* map, int x, int y) {
    if (x >= 0 && x < map->rows && y >= 0 && y < map->cols) {
        return map->data[x][y];
    }
    return 'b';
}

void print_map(const Map* map) {
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            printf("%c", map->data[i][j]);
        }
        printf("\n");
    }
}
