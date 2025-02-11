#ifndef MAP_H
#define MAP_H

// Térkép struktúra
typedef struct {
    char **data;  // Térkép adatainak tárolása (kétdimenziós tömb)
    int rows;     // Térkép sorainak száma
    int cols;     // Térkép oszlopainak száma
} Map;

Map* create_map(int rows, int cols);
void map_initialization(Map* map, char , char value2);
void set_value(Map* map, int x, int y, char value);
char get_value(Map* map, int x, int y);
void print_map(const Map* map);

#endif // MAP_H
