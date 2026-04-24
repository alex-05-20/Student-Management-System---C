#include "etudiant.h"
#include<stdio.h>
#include "CDS.h"
#define Currentyear 2025

///INPUT CONTROL FOR DATE OF BIRTH

int estBissextile(int annee) {
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        return 1; // leap year
    }
    return 0; // non-leap year
}

// Function to check if a date is valid
int estDateValide(date d) {
    if (d.mois < 1 || d.mois > 12) {
        return 0; // Invalid month
    }

    // Number of days in each month
    int joursDansMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If it's a leap year, February has 29 days
    if (estBissextile(d.annee)) {
        joursDansMois[1] = 29;
    }

    // Check the day
    if (d.jour < 1 || d.jour > joursDansMois[d.mois - 1]) {
        return 0; // Invalid day for this month
    }
    if(d.annee > Currentyear){ return 0; }

    return 1; // Valid date
}

// Function to enter a date and return it once validated
date saisirDate() {
    date d;
    int valide;

    do {
        printf("Enter the date (day/month/year): ");
        scanf("%d/%d/%d", &d.jour, &d.mois, &d.annee);

        valide = estDateValide(d);
        if (!valide) {
            printf("INVALID DATE, PLEASE TRY AGAIN.\n");
        }
    } while (!valide); // As long as the date is not valid, ask again

    return d; // Return the valid date
}

///MENU FUNCTION

void menu()
{
    printf("\n///////////////////////   M E N U   /////////////////////\n");
    printf("\n");
    printf(" 1 - ENTER STUDENT\n");
    printf(" 2 - LIST STUDENTS\n");
    printf(" 3 - ENTER SUBJECT\n");
    printf(" 4 - LIST SUBJECTS\n");
    printf(" 5 - ENTER GRADES\n");
    printf(" 6 - DISPLAY GRADES\n");
    printf(" 7 - STUDENT AVERAGES\n");
    printf(" 8 - EDIT GRADES\n");
    printf(" 9 - DELETE GRADES\n");
    printf(" 10 - STUDENT REPORT CARD\n");
    printf(" 11 - CLASS AVERAGE FOR ALL STUDENTS\n");
    printf(" 12 - EXIT\n");
    printf("\n       ENTER YOUR CHOICE ***   ");
};

///FUNCTION FOR ENTERING STUDENT DATA

etudiant saisieetud()
{
    int existe;
    etudiant E;
    fflush(stdin);
    printf("\n");
    do {
        printf("Enter the student's name: \n");
        fgets(E.nom, sizeof(E.nom), stdin);
        printf("Enter the student's ID: \n");
        fgets(E.matricule, sizeof(E.matricule), stdin);
        existe = etudiantexise(E.matricule, E.nom);
    } while(existe == 1);

    printf("Enter the date of birth in numbers\n");
    ///DATE INPUT VALIDATION///
    E.naissance = saisirDate();
    ///
    printf("Enter gender (M/F): ");
    fflush(stdin);
    do {
        fgets(E.sexe, sizeof(E.sexe), stdin);
    } while(strcmp(E.sexe,"M\n") != 0 && strcmp(E.sexe,"F\n") != 0);

    printf("Enter your major: ");
    gets(E.filliere);
    return E;
}

/////////CALL STUDENT FUNCTION///////////

void fichetud()
{
    int c = 0;
    etudiant E;
    FILE *e = fopen("fetud.ing","a+");
    if(e == NULL)
        printf("Problem opening file");
    else
    {
        while(c == 0)
        {
            printf("Enter student information");
            printf("\n");
            E = saisieetud();
            fwrite(&E, sizeof(E), 1, e);
            printf("\n");
            printf("Do you want to continue entering students?\n");
            printf(" 0 = YES and  1 = NO    :");
            scanf("%d", &c);
            if(c == 1)
            {
                system("cls");
                break;
            }
            system("cls");
        }
        fclose(e);
    }
}

///////////////DISPLAY STUDENT LIST/////////////////////////

void listeetudiant(){
    etudiant E;
    FILE *e = fopen("fetud.ing","r+");
    if(e == NULL)
        printf("Problem opening file");
    else {
        while(!feof(e) && fread(&E, sizeof(E), 1, e) == 1){
            printf("\n");
            printf("ID : ");
            puts(E.matricule);
            printf("NAME : ");
            puts(E.nom);
            printf("Date of birth  : %d / %d / %d \n", E.naissance.jour, E.naissance.mois, E.naissance.annee);
            printf("GENDER : ");
            puts(E.sexe);
            printf("MAJOR : ");
            puts(E.filliere);
            printf("\n-------------------------------------------------------------------------------------");
        }
        fclose(e);
        sortir();
    }
}

