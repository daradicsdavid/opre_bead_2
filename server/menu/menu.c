#include <stdio.h>
#include "../read/read.h"

void printMainMenu() {
    printf("(0) Rendelés leadás\n");
    printf("(1) Rendelés módosítás\n");
    printf("(2) Rendelés törlés\n");
    printf("(3) Rendelés listázás\n");
    printf("(4) Rendelés keresés\n");
    printf("(5) Kilépés\n");
}

boolean askMainMenu(int *command) {
    printf("Adjon meg egy parancsot(0-5):");
    readInt(command);
    if (*command < 0 || *command > 5) {
        return false;

    }
    return true;
}

void printFilterMenu() {
    printf("(0) Szűrés név alapján\n");
    printf("(1) Szűrés teljesítmény igény szerint\n");
    printf("(2) Vissza\n");
}

boolean askFilterMenu(int *command) {
    printf("Adjon meg egy parancsot(0-2):");
    readInt(command);
    if (*command < 0 || *command > 2) {
        return false;

    }
    return true;
}