
//your project’s title : STUDENT MONITOR
//your name : TSAPI KOUDJOU Alex Cabrel
//your GitHub usernames : alex-05-20
//edX username : alex05_5
//your city and country : YAOUNDE CAMEROUN
//The date you have recorded this video : 21/08/2025


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "etudiant.h"
#include "note.h"
#include "matiere.h"
#include "mesfonctions.h"
#include "code.h"

const int N = 10; ///NUMBER OF SEQUENCES///

int main()
{
    int choix, seq;
    char code[20];
    char mat[20];
    struct moyen moy;

    do {
        Cadre(5,75,5,75,9);
        choix = affichage(7,7,15);
        fflush(stdin);

        switch (choix) {

        case 1:
            system("cls");
            printf("\n    ***ENTER STUDENT INFORMATION***   \n");
            fichetud();
            break;

        case 2:
            system("cls");
            printf("\n    ***LIST OF STUDENTS***   \n");
            listeetudiant();
            break;

        case 3:
            system("cls");
            printf("\n    ***ENTER SUBJECT INFORMATION***   \n");
            fichmat();
            break;

        case 4:
            system("cls");
            printf("\n    ***LIST OF SUBJECTS***   \n");
            listematiere();
            break;

        case 5:
            system("cls");
            printf("\n    ***ENTER GRADES***   \n");
            fichnote();
            break;

        case 6:
            system("cls");
            printf("\n          ***LIST OF GRADES***  \n\n");
            listenotes();
            break;

        case 7:
            system("cls");
            printf("\n    ***STUDENT AVERAGE***   \n");
            printf("Enter the student ID whose average you want to calculate\n");
            fgets(code, sizeof(code), stdin);
            printf("Enter the sequence for which you want to calculate the average\n");
            scanf("%d", &seq);
            moy = MoyEtud(code, seq);
            printf("The student's average is: %f", moy.Valeur);
            sortir();
            system("cls");
            break;

        case 8:
            system("cls");
            printf("\n    ***EDIT GRADE***   \n");
            puts("Enter the code of the grade you want to edit");
            fgets(code, sizeof(code), stdin);
            puts("Enter the student ID");
            fgets(mat, sizeof(mat), stdin);
            puts("Enter the sequence");
            scanf("%d", &seq);
            modifiernote(code, mat, seq);
            break;

        case 9:
            system("cls");
            printf("\n    ***DELETE GRADE***   \n");
            puts("Enter the code of the grade you want to delete");
            fgets(code, sizeof(code), stdin);
            puts("Enter the student ID");
            fgets(mat, sizeof(mat), stdin);
            puts("Enter the sequence");
            scanf("%d", &seq);
            supprimernote(code, mat, seq);
            break;

        case 10:
            system("cls");
            printf("\n    ***STUDENT REPORT CARD***   \n");
            printf("Enter the student ID: \n");
            fgets(code, sizeof(code), stdin);
            genererPV(code);
            sortir();
            break;

        case 11:
            system("cls");
            printf("\n    ***CLASS STUDENT AVERAGES***   \n");
            Affiche_Moyennes();
            sortir();
            break;
        }
    } while (choix != 12);

    return 0;
}
