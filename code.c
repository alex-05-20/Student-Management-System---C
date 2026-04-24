#include "code.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*

x corresponds to the text color
y corresponds to the background color

Values:
0: black
1: dark blue
2: green
3: blue-gray
4: brown
5: purple
6: khaki
7: light gray
8: gray
9: blue
10: bright green
11: turquoise
12: red
13: bright pink
14: bright yellow
15: white
*/
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

void gotoxy(int x, int y)
{
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   //cout.flush();
   dwCursorPosition.X = x;
   dwCursorPosition.Y = y;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

/// DRAWING THE PROGRAM FRAME
void Cadre(int x1, int x2, int y1, int y2, int c) {
    int i, j;
    color(c, 0); // Set the border color

    for(i=x1;i<x2;i++){
        gotoxy(i,y1);
        printf("%c", 196);
        gotoxy(i,y2);
        printf("%c",  196);
    }
    for(j=y1;j<y2;j++){
        gotoxy(x1,j);
        printf("%c", 179);
        gotoxy(x2,j);
        printf("%c", 179);
    }
    gotoxy(x1,y1-1);
    printf("%c", 218);
    gotoxy(x2,y1-1);
    printf("%c", 191);
   // gotoxy(x1,y2);
   // printf("%c", 192);
  //  gotoxy(x2,y2);
   // printf("%c", 217);
}

/// MENU DISPLAY
int affichage(int x, int y, int C){
     int ch;
     char MENU[12][100]={" 1 - ENTER STUDENT", " 2 - STUDENT LIST", " 3 - ENTER SUBJECT", " 4 - SUBJECT LIST", " 5 - ENTER GRADES", " 6 - SHOW GRADES", " 7 - STUDENT AVERAGE", " 8 - MODIFY GRADES", " 9 - DELETE GRADES", " 10 - STUDENT REPORT CARD", " 11 - CLASS AVERAGE FOR ALL STUDENTS", " 12 - EXIT"};
     color(C,0);
     int c;
     int cpt=0;
     do{
        gotoxy(x+1,y+1);printf("***********************   M E N U   *****************************");
        for(int i=0;i<12;i++){
            if(i==cpt){color(C, 8);gotoxy(x+1,y+2+i); printf("%s\n", MENU[i]);}
            else{ color(C, 0);gotoxy(x+1,y+2+i); printf("%s\n", MENU[i]); }
        }
        c=getch();
        if(c==80){
            if(cpt<12-1) cpt++;
        }
        else if(c==72){
            if(cpt>0) cpt--;
        }

     }while(c!=13);
     return cpt+1;
}

