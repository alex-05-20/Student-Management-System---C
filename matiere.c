#include<stdio.h>
#include "matiere.h"
#include "CDS.h"

///SUBJECT INPUT///

matiere saisiemat()
{
    fflush(stdin);
    matiere M;
    int existe;
    puts("Enter the subject code");
    fgets(M.code, sizeof(M.code), stdin);
    fflush(stdin);
    puts("Enter the subject name");
    fgets(M.nom, sizeof(M.nom), stdin);
    puts("Enter the number of credits for the subject");
    do {
        scanf("%d", &M.credit);
    } while(M.credit < 0 || M.credit > 10);
    return M;
}

///SAVE SUBJECT TO FILE///

void fichmat()
{
    int b = 0;
    matiere M;
    fflush(stdin);
    FILE *m = fopen("fmatiere.ing","a+");
    if(m == NULL)
        printf("Problem opening file");
    else {
        while(b == 0) {
            printf("Enter subject information");
            printf("\n");
            M = saisiemat();
            fwrite(&M, sizeof(M), 1, m);
            printf("\n");
            printf("Do you want to continue entering subjects?\n");
            printf(" 0 = YES    and    1 = NO  \n");
            scanf("%d", &b);
            if(b == 1) {
                system("cls");
                break;
            }
            system("cls");
        }
        fclose(m);
    }
}

///LIST SUBJECTS///////

void listematiere(){
    fflush(stdin);
    matiere M;
    FILE *m = fopen("fmatiere.ing","r");
    if(m == NULL)
        printf("Problem opening file");
    else {
        while(!feof(m) && fread(&M, sizeof(M), 1, m) == 1){
            printf("\n");
            printf("CODE : ");
            puts(M.code);
            printf("NAME : ");
            puts(M.nom);
            printf("NUMBER OF CREDITS : ");
            printf("%d", M.credit);
            printf("\n-------------------------------------------------------------------------------------");
        }
        fclose(m);
        sortir();
    }
}
