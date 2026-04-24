#include<stdio.h>
#include<string.h>
#include "etudiant.h"
#include "note.h"
#include "matiere.h"
#include "mesfonctions.h"
#include "code.h"

int v=0;

/// Remove the newline character
char enleverNouvelleLigne(char str[])
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';  // Replace '\n' with '\0' to terminate the string
    }
    return str;
}

/// STUDENT REPORT ///
void genererPV(char matricule[])
{
    FILE *e = fopen("fetud.ing", "r");
    if (e == NULL)
    {
        printf("Problem opening the student file.\n");
        return;
    }

    FILE *n = fopen("fnote.ing", "r");
    FILE *m = fopen("fmatiere.ing", "r");
    if (n == NULL || m == NULL)
    {
        printf("Problem opening grades or subjects file.\n");
        fclose(e);
        return;
    }

    etudiant E;
    note N;
    matiere M;
    int foundStudent = 0;

    while (fread(&E, sizeof(E), 1, e) == 1)
    {
        if (strcmp(E.matricule, matricule) == 0)
        {
            foundStudent = 1;
            system("cls");
            printf("**************************************************************************************\n\n");
            color(9,0);
            printf("                           STUDENT REPORT\n\n");color(15,0);
            printf("**************************************************************************************\n\n");
            printf("Name: %s\n", E.nom);
            printf("Student ID: %s\n", E.matricule);
            printf("Date of Birth: %d/%d/%d\n", E.naissance.jour, E.naissance.mois, E.naissance.annee);
            printf("Gender: %s\n", E.sexe);
            printf("Program: %s\n\n", E.filliere);
            printf("***************************************************************************************\n\n");
            color(9,0);
            printf("                  *********GRADES*********   \n\n");color(15,0);
            printf("SUBJECT           CODE            GRADE            CREDIT\n");
            printf("---------------------------------------------------------------\n");

            // Iterate over grades and match with subjects
            while (fread(&N, sizeof(N), 1, n) == 1)
            {
                if (strcmp(N.matricule, matricule) == 0)
                {
                    // Rewind subject file
                    rewind(m);
                    while (fread(&M, sizeof(M), 1, m) == 1)
                    {
                        if (strcmp(N.code, M.code) == 0)
                        {
                            // Remove '\n' before displaying
                            enleverNouvelleLigne(M.nom);
                            enleverNouvelleLigne(M.code);
                            printf("%-16s %-15s %-16.2f %-6d\n", M.nom, M.code, N.note, M.credit);
                        }
                    }
                }
            }
            Moyen M=MoyEtud(matricule,1);
            printf(" \n                                  ANNUAL AVERAGE: %f", M.Valeur);

            break; // Exit once the student is found and printed
        }
    }

    if (!foundStudent)
    {
        printf("NO STUDENT FOUND WITH THIS ID %s.\n", matricule);
    }

    fclose(e);
    fclose(n);
    fclose(m);
}

/// DELETE A GRADE ///
void supprimernote(char code[], char matricule[], int seq)
{
    note N;
    int found = 0;
    FILE *n = fopen("fnote.ing", "r");
    if (n == NULL)
    {
        puts("PROBLEM OPENING GRADES FILE");
        return;
    }

    FILE *temp = fopen("tempfile.ing", "w");
    if (temp == NULL)
    {
        puts("PROBLEM OPENING TEMPORARY FILE.");
        fclose(n);
        return;
    }
    int sure;

    while (fread(&N, sizeof(N), 1, n) == 1)
    {
        if (strcmp(N.matricule, matricule) == 0 && strcmp(N.code, code) == 0 && N.sequence==seq)
        {
            found = 1;
            if(v!=0){printf("\nARE YOU SURE YOU WANT TO MODIFY THIS GRADE? TYPE 0=YES  1=NO\n");}
            if(v==0){printf("\nARE YOU SURE YOU WANT TO DELETE THIS GRADE? TYPE 0=YES  1=NO\n");}
            scanf("%d", &sure);
            if(sure==1)
            {
                fwrite(&N, sizeof(N), 1, temp);
            }
        }
        else
        {
            fwrite(&N, sizeof(N), 1, temp);
        }
    }

    fclose(n);
    fclose(temp);

    if (found)
    {
        remove("fnote.ing");
        rename("tempfile.ing", "fnote.ing");
        if(sure==0)
        {
            printf("GRADE HAS BEEN DELETED.\n");
        }
        sortir();
    }
    else
    {
        remove("tempfile.ing");
        printf("NO GRADE FOUND FOR THIS STUDENT WITH THE GIVEN CODE.\n");
        sortir();
    }
}

/// MODIFY A GRADE ///
void modifiernote(char matricule[], char code[], int seq)
{
    v++;
    note N;
    supprimernote(matricule,code,seq);
    fflush(stdin);
    printf("\nENTER THE NEW GRADE FOR THE MODIFIED STUDENT\n");
    fichnote();
    v=0;
}

/// CHECK IF FILE IS EMPTY ///
int Vide(char File[])
{
    FILE *f=fopen(File, "r");
    int c;
    if(f==NULL)
        printf("Error opening file");
    else
    {
        c=fgetc(f);
        fclose(f);
        return(c==EOF);
    }
}

/// SMALL FUNCTION TO FIND A GRADE ///
float TrouveNote(char MatEtud[], char CodeMat[], int Seq)
{
    FILE *f=fopen("fnote.ing", "r");
    note Note;
    float note=-1;
    if(f==NULL)
    {
        printf("PROBLEM OPENING \"fnote.ing\" in \"TrouveNote\"!!!\n");
    }
    else
    {
        if(Vide("fnote.ing")==1)
        {
            printf("The file is empty\n");
            return -1;
        }
        else
        {
            while(!feof(f) && fread(&Note, sizeof(Note), 1, f)!=0)
            {
                if(strcmp(Note.matricule, MatEtud)==0 && strcmp(Note.code, CodeMat)==0 && Note.sequence==Seq)
                {
                    note=Note.note;
                    break;
                }
                note=-1;
            }
            fclose(f);
            return note;
        }
    }
    fclose(f);
}

/// STUDENT AVERAGE FOR THE CLASS ///
Moyen MoyEtud(char Matri[], int Seq)
{
    fflush(stdin);
    FILE *f=fopen("fmatiere.ing", "r");
    matiere Mat;
    float note, Som=0;
    int cpt=0, SommeCredits=0;
    Moyen Moy;

    if (f==NULL)
        printf("PROBLEM OPENING \"fmatiere.ing\" in \"MoyEtud\"\n ");
    else
    {
        while(fread(&Mat, sizeof(Mat), 1, f)!=0)
        {
            note=TrouveNote(Matri, Mat.code, Seq);
            if(note>=0)
            {
                Som=Som + note*Mat.credit;
                SommeCredits = SommeCredits + Mat.credit;
                cpt++;
            }
        }
    }
    Moy.Nombres=cpt;
    if(cpt>0)
        Moy.Valeur=Som/SommeCredits;
    else Moy.Valeur=-1;
    fclose(f);

    return Moy;
}

/// DISPLAY AVERAGES ///
void Affiche_Moyennes()
{
    int N;
    printf("ENTER THE NUMBER OF SEQUENCES YOU WANT TO CALCULATE THE AVERAGE FOR\n");
    scanf("%d", &N);
    FILE *f=fopen("fetud.ing", "r"), *g=fopen("fmatiere.ing", "r");
    etudiant Etud;
    matiere Mat;
    Moyen Moy;

    char Matri[10];
    float Somme, SommeCredits;
    int choix, Seq, t=0;

    printf("**************CLASS STUDENTS' AVERAGES***************\n");
    if(Vide("fetud,ing")==1)
    {
        printf("No students are registered.\n");
        if(Vide("fmat.ing")==1)
        {
            printf("No subjects are registered.\n");
            if(Vide("fnote.ing")==1)
                printf("No grades are recorded.\n");
        }
    }
    else
    {
        system("cls");
        printf("**************CLASS STUDENTS' AVERAGES***************\n");
        if (f==NULL || g==NULL)
        {
            if(f==NULL)
                printf("PROBLEM OPENING \"fetud.ing\"!!!\n");
            else
                printf("PROBLEM OPENING \"fmat.ing\"!!!\n");
        }
        else
        {
            while(fread(&Etud, sizeof(Etud), 1, f)!=0)
            {
                for(int i=0; i<N; i++)
                {
                    Moy=MoyEtud(Etud.matricule, i+1);
                    if(Moy.Valeur>0)
                        printf("Student %s Sequence %d\tAverage: %f (Number of subjects %d)\n", Etud.nom, i+1, Moy.Valeur, Moy.Nombres);
                    else printf("Sequence %d\tAverage: Not available\n", i+1);
                }
            }
        }
        fclose(g);
        fclose(f);
    }
}

