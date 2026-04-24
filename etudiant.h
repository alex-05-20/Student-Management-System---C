#ifndef H_ETUDIANT_H
struct Date{
       int jour;
       int mois;
       int annee;
     };
typedef struct Date date;

struct Etudiant{
       char matricule[10];
       char nom[50];
       date naissance;
       char sexe[4];
       char filliere[10];
};
typedef struct Etudiant etudiant;
#endif // H_ETUDIANT_H
