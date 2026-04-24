/// CDS = INPUT CONTROL ///
#include <stdio.h>
#include <string.h>
#include "CDS.h"
#include <stdbool.h>
#include "etudiant.h"
#include "note.h"
#include "matiere.h"

/// SMALL EXIT FUNCTION ///

void sortir() {
    int sortir;
    printf("\n");
    printf("\n ********** PRESS 1 TO EXIT   :   ");
    do
        scanf("%d", &sortir);
    while (sortir != 1);
    system("cls");
}

/// INPUT CONTROL FOR FLOAT VALUES ///

float cdsfloat(float a, float b) {
    float val;
    do
        scanf("%f", &val);
    while (val < a && val > b);
}

/// INPUT CONTROL FOR INT VALUES ///

int cdsint(int a, int b) {
    int val;
    do
        scanf("%d", &val);
    while (val < a && val > b);
}

/// CHECK IF STUDENT FILE IS EMPTY ///

int vide(char filename[]) {
    FILE *e = fopen(filename, "r");
    int c;
    if (e == NULL)
        printf("OPENING ERROR");
    else {
        c = fgetc(e);
        fclose(e);

        return (c == EOF);   /// returns 1 if the file is empty and 0 otherwise
    }
    fclose(e);
}

/// CHECK IF STUDENT ALREADY EXISTS IN STUDENT LIST ///

int etudiantexise(char matricule[], char name[]) {
    FILE *e = fopen("fetud.ing", "r");
    etudiant E;
    if (e == NULL)
        printf("OPENING ERROR");
    else {
        while (!feof(e) && fread(&E, sizeof(E), 1, e) == 1) {
            if (strcmp(E.matricule, matricule) == 0) {
                if (strcmp(tolower(E.nom), tolower(name)) == 0)  /// IF NAME AND MATRICULE ARE THE SAME ///
                    printf(" THIS STUDENT ALREADY EXISTS\n ");
                else
                    printf(" A STUDENT ALREADY EXISTS WITH THIS MATRICULE\n");
                return 1;
            }
        }
    }
    fclose(e);
    return 0;
}

/// CHECK IF COURSE ALREADY EXISTS IN COURSE LIST ///

int matiereexiste(char code[], char name[]) {
    matiere M;
    FILE *m = fopen("fmatiere.ing", "r");

    while (!feof(m) && fread(&M, sizeof(M), 1, m) == 1) {
        if (strcmp(M.code, code) == 0) {
            if (strcmp(tolower(M.nom), tolower(name)) == 0)
                printf("THIS COURSE ALREADY EXISTS\n");
            else
                printf("A COURSE ALREADY EXISTS WITH THIS CODE\n");
            return 1;
        }
    }
    return 0;
}

/// CHECK IF GRADE ALREADY EXISTS ///

int noteexiste(char code[], char matricule[], int seq) {
    FILE *n = fopen("fnote.ing", "r");
    struct Note N;
    while (!feof(n) && fread(&N, sizeof(N), 1, n) == 1) {
        if (strcmp(tolower(code), tolower(N.code)) == 0 &&
            strcmp(tolower(N.matricule), tolower(matricule)) == 0 &&
            N.sequence == seq) {
            printf("\nTHIS GRADE ALREADY EXISTS\n");
            return 1;
        }
    }
    return 0;
}

/// CHECK IF STUDENT EXISTS IN STUDENT LIST ///

int verifetudiant(char matricule[]) {
    FILE *e = fopen("fetud.ing", "r");
    etudiant E;
    int exists = 0;
    if (e == NULL)
        printf("OPENING ERROR");
    else {
        while (!feof(e) && fread(&E, sizeof(E), 1, e) == 1) {
            if (strcmp(tolower(E.matricule), tolower(matricule)) == 0)
                exists = 1;
        }
    }
    fclose(e);
    return exists;
}

/// CHECK IF COURSE CODE IS VALID ///

int verifmatiere(char code[]) {
    matiere M;
    int exists = 0;
    FILE *m = fopen("fmatiere.ing", "r");
    rewind(m);
    while (!feof(m) && fread(&M, sizeof(M), 1, m) == 1) {
        if (strcmp(tolower(M.code), tolower(code)) == 0) {
            exists = 1;
        }
    }
    fclose(m);
    return exists;
}
