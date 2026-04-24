#include <stdio.h>
#include "note.h"
#include "CDS.h"

/// ENTER GRADES ///
note saisienote() {
    fflush(stdin);
    struct Note N;
    int existe;
    do {
        fflush(stdin);
        int lol;
        do {
            puts("ENTER THE SUBJECT CODE: ");
            fgets(N.code, sizeof(N.code), stdin);
            lol = verifmatiere(N.code);
            if(lol == 0){
                printf("\n   ********THIS CODE DOES NOT EXIST IN THE SUBJECT FILE\n");
            }
        } while(lol != 1);

        do {
            puts("ENTER THE STUDENT ID: ");
            fgets(N.matricule, sizeof(N.matricule), stdin);
            lol = verifetudiant(N.matricule);
            if(lol != 1){
                printf("\n     *******THIS STUDENT ID DOES NOT EXIST IN THE STUDENT FILE\n");
            }
        } while(lol == 0);

        puts("Enter the sequence number: ");
        do {
            scanf("%d", &N.sequence);
        } while(N.sequence < 0);

        existe = noteexiste(N.code, N.matricule, N.sequence);
    } while(existe == 1);

    puts("Enter the grade value (0–20): ");
    do {
        scanf("%f", &N.note);
    } while(N.note < 0 || N.note > 20);

    return N;
}

/// SAVE GRADES TO FILE ///
void fichnote() {
    int b = 0;
    note N;
    FILE *n = fopen("fnote.ing", "a+");
    if (n == NULL) {
        printf("Problem opening file\n");
        return;
    }

    while (b == 0) {
        printf("Enter grade information\n");
        N = saisienote();
        fwrite(&N, sizeof(note), 1, n);

        printf("\nDo you want to continue entering grades?\n");
        printf("0 = YES and 1 = NO\n");
        scanf("%d", &b);

        if (b == 1) {
            system("cls");
            break;
        }

        system("cls");
    }

    fclose(n);
}

/// DISPLAY GRADES ///
void listenotes() {
    fflush(stdin);
    note N;
    FILE *n = fopen("fnote.ing", "r");
    if (n == NULL) {
        printf("Problem opening file\n");
    } else {
        while (fread(&N, sizeof(N), 1, n) == 1) {
            printf("\nCODE: ");
            puts(N.code);
            printf("STUDENT ID: ");
            puts(N.matricule);
            printf("SEQUENCE NUMBER: ");
            printf("%d\n", N.sequence);
            printf("GRADE VALUE: ");
            printf("%f\n", N.note);
            printf("-------------------------------------------------------------------------------------\n");
        }
    }
    fclose(n);
    sortir();
}
