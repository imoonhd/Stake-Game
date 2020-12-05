#include <stdio.h>
#include <stdlib.h>

void initialisation(char tab[5][5], char tablo[12][5], char tabo[11])
{
    int i=0, j=0;
    for(i=0;i<5;i=i+1)
    {
        int j=0;
        for (j=0;j<5;j=j+1)
        {
            tab[i][j]=' ';
        }
    }
    for(i=0;i<12;i=i+1)
    {
        for (j=0;j<5;j=j+1)
        {
            tablo[i][j]=' ';
        }
    }
    // première colonne
    tabo[2]='A';
    tabo[4]='B';
    tabo[6]='C';
    tabo[8]='D';
    tabo[10]='E';
}

int convertisseur1(int X, char x)
{
    X=x-65; // code ascii commence à 65 puis croît
    return X;
}

int convertisseur2(int Y, int y)
{
    Y=y-1; // tableau commence à 0
    return Y;
}

int convertisseurinverse1(int O, char o)
{
    o=O+65;
    return o;
}

int convertisseurinverse2(int L, int l)
{
    l=L+1;
    return l;
}

void etirement(char tablo[12][5],char tab[5][5])
{
    int k=2, i=0, j=0;
    while(i<5)
    {
        while(j<5)
        {   tablo[k][j]=tab[i][j];
            j++;
        }
        k=k+2;
        i++;
        j=0;
    }

}

void affichage(char tabo[11], char tablo[12][5])
{

    int h=0;     // indice de ligne
    while(h<12)
    {
        if(h==0)
        {
            printf("    1   2   3   4   5\n");     // première ligne
        }

        if((h%2)==1)
        {
            printf("  +---+---+---+---+---+\n");     //interlignes
        }

        else if(h>1)
        {
            printf("%c | %c | %c | %c | %c | %c |\n", tabo[h],tablo[h][0],tablo[h][1],tablo[h][2],tablo[h][3],tablo[h][4]);     //lignes de jeu
        }

        h++;
    }

}

void checkautourx(char tab[5][5], char X, int Y)
{
    if(Y==0) // zone 2 (en bas a gauche)
    {
        if (tab[X-1][Y]==' ') // haut vide -> x
        {
            tab[X-1][Y]='x';
        }
        if (tab[X+1][Y]==' ') // bas vide -> x
        {
            tab[X+1][Y]='x';
        }
        if (tab[X][Y+1]==' ') // droite "
        {
            tab[X][Y+1]='x';
        }
        if (tab[X-1][Y]=='o') // haut o -> #
        {
            tab[X-1][Y]='#';
        }
        if (tab[X+1][Y]=='o') // bas
        {
            tab[X+1][Y]='#';
        }
        if (tab[X][Y+1]=='o') // droite
        {
            tab[X][Y+1]='#';
        }
    }

    if(Y==4) // zone 3 (en haut à droite)
    {
        if (tab[X-1][Y]==' ') // haut vide -> x
        {
            tab[X-1][Y]='x';
        }
        if (tab[X+1][Y]==' ') // bas vide -> x
        {
            tab[X+1][Y]='x';
        }
        if (tab[X][Y-1]==' ') // gauche "
        {
            tab[X][Y-1]='x';
        }
        if (tab[X-1][Y]=='o') // haut o -> #
        {
            tab[X-1][Y]='#';
        }
        if (tab[X+1][Y]=='o') // bas
        {
            tab[X+1][Y]='#';
        }
        if (tab[X][Y-1]=='o') // gauche
        {
            tab[X][Y-1]='#';
        }
    }

    if((Y==1)|(Y==2)|(Y==3))
    {
        if (tab[X-1][Y]==' ') // haut vide -> x
        {
            tab[X-1][Y]='x';
        }
        if (tab[X+1][Y]==' ') // bas vide -> x
        {
            tab[X+1][Y]='x';
        }
        if (tab[X][Y+1]==' ') // droite "
        {
            tab[X][Y+1]='x';
        }
        if (tab[X][Y-1]==' ') // gauche "
        {
            tab[X][Y-1]='x';
        }
        if (tab[X-1][Y]=='o') // haut o -> #
        {
            tab[X-1][Y]='#';
        }
        if (tab[X+1][Y]=='o') // bas
        {
            tab[X+1][Y]='#';
        }
        if (tab[X][Y+1]=='o') // droite
        {
            tab[X][Y+1]='#';
        }
        if (tab[X][Y-1]=='o') // gauche
        {
            tab[X][Y-1]='#';
        }
    }
}

void checkautouro(char tab[5][5], int X, int Y)
{
     if(Y==0) // zone 2 (en bas a gauche)
    {
        if (tab[X-1][Y]==' ') // haut vide -> x
        {
            tab[X-1][Y]='o';
        }
        if (tab[X+1][Y]==' ') // bas vide -> x
        {
            tab[X+1][Y]='o';
        }
        if (tab[X][Y+1]==' ') // droite "
        {
            tab[X][Y+1]='o';
        }
        if (tab[X-1][Y]=='x') // haut o -> #
        {
            tab[X-1][Y]='#';
        }
        if (tab[X+1][Y]=='x') // bas
        {
            tab[X+1][Y]='#';
        }
        if (tab[X][Y+1]=='x') // droite
        {
            tab[X][Y+1]='#';
        }
    }

    if(Y==4) // zone 3 (en haut à droite)
    {
        if (tab[X-1][Y]==' ') // haut vide -> x
        {
            tab[X-1][Y]='o';
        }
        if (tab[X+1][Y]==' ') // bas vide -> x
        {
            tab[X+1][Y]='o';
        }
        if (tab[X][Y-1]==' ') // gauche "
        {
            tab[X][Y-1]='o';
        }
        if (tab[X-1][Y]=='x') // haut o -> #
        {
            tab[X-1][Y]='#';
        }
        if (tab[X+1][Y]=='x') // bas
        {
            tab[X+1][Y]='#';
        }
        if (tab[X][Y-1]=='x') // gauche
        {
            tab[X][Y-1]='#';
        }
    }

    if((Y==1)|(Y==2)|(Y==3)) // zone 1 (au middle)
    {
        if (tab[X-1][Y]==' ') // haut vide -> x
        {
            tab[X-1][Y]='o';
        }
        if (tab[X+1][Y]==' ') // bas vide -> x
        {
            tab[X+1][Y]='o';
        }
        if (tab[X][Y+1]==' ') // droite "
        {
            tab[X][Y+1]='o';
        }
        if (tab[X][Y-1]==' ') // gauche "
        {
            tab[X][Y-1]='o';
        }
        if (tab[X-1][Y]=='x') // haut o -> #
        {
            tab[X-1][Y]='#';
        }
        if (tab[X+1][Y]=='x') // bas
        {
            tab[X+1][Y]='#';
        }
        if (tab[X][Y+1]=='x') // droite
        {
            tab[X][Y+1]='#';
        }
        if (tab[X][Y-1]=='x') // gauche
        {
            tab[X][Y-1]='#';
        }
    }
}

int jouabilite(char tab[5][5], int z)
{
    int d=0;
    for(d=0; d<5; d=d+1)
    {
        int f=0;
        for (f=0;f<5;f=f+1)
        {
            if (tab[d][f]==' ')
            {
                z=1;
            }
        }
    }
    return z;
}

int changementderole(int t)
{
    if(t==0)
    {
        t=1;
    }
    else
    {
        t=0;
    }
    return t;
}

void whoisthewinner(char tab[5][5])
{
    int w=0, v=0; // compteur de pounto / w human - v robot
    int i=0;
    for(i=0;i<5;i=i+1)
    {
        int j=0;
        for (j=0;j<5;j=j+1)
        {
            if(tab[i][j]=='X')
            {
                w=w+4;
            }
            if(tab[i][j]=='x')
            {
                w=w+1;
            }
            if(tab[i][j]=='O')
            {
                v=v+4;
            }
            if(tab[i][j]=='o')
            {
                v=v+1;
            }

        }
    }
    if(w>v)
    {
        printf("\nTu es le vainceur avec un total de %d points contre %d points pour ton adversaire !\n", w, v);
    }
    if(v>w)
    {
        printf("\nTu as perdu avec un total de %d points contre %d points pour ton adversaire !\n", w, v);
    }
    if(v==w)
    {
        printf("\nEx aequo à %d points !\n", w);
    }
}

int main()
{
    char tab[5][5]; // Le 5x5 de base sur lequel on travail
    char tabo[11];  // première colonne (A, B, C,...) (adapté pour l'affichage)
    char tablo[12][5]; // l'étiré (adapté  pour l'affichage)
    char x=NULL ,o=NULL;  // coordonnées (ligne) d'attaque // coordonnée d'attaque de l'ordi
    int y=0, t=0, u=0; // coordonnées (colonne) d'attaque,
    // t = joueur | 0 : nous / 1 : PC // u = action réalisé ? 0-non / 1-oui
    int z=1; // z = booléen de jouabilité
    int X, Y, O, L;
    int s, e, a=0;
    int l=0; // coordonnées d'attaque de l'ordi
    int d=0; // pb du premier while pour affichier ce que joue l'ordi (0)
    int u2=1; // u2 : action réalisé interne pour faire Y joue 0 en cas d'erreur de case de la part de l'user
    int modeia=0;
    int iapasconfig=0;

    while((modeia!=1)&(modeia!=2))
    {
        printf("Entrer l'IA contre lequel vous desirer jouer.\n\n 1 - Debile\n 2 - Un peu plus sophistiquee\n\n");
        printf("IA choisis : ");
        scanf("%d", &modeia);
        if((modeia!=1)&(modeia!=2))
        {
            system("cls");
            printf("!!! Veuillez choisir un numero d'IA correct !!!\n\n");
        }
    }

    system("cls");

    initialisation(tab, tablo, tabo);  // sur mesure*
    etirement(tablo,tab);              // sur mesure*
    affichage(tabo, tablo);



    while(z==1) //tant que c'est jouable
    {
        if(t==0) // USER (humain/utilisateur)
        {
            while(u==0)
            {
                if(d!=0)
                {
                    o=convertisseurinverse1(O,o);
                    l=convertisseurinverse2(L,l);
                }
                d=1;

                if((u2==0)|(iapasconfig==1))
                {
                    printf ("\nX joue : %c%d\nY joue :  0\n\nQuelle case voulez vous attaquer ?\n\n", x, y);
                }
                //if((u2==1)(iapasconfig=0))
                else
                {
                    printf ("\nX joue : %c%d\nY joue : %c%d\n\nQuelle case voulez vous attaquer ?\n\n", x, y, o, l);
                }

                scanf("%c%d", &x, &y);
                X=convertisseur1(X,x);
                Y=convertisseur2(Y,y);

       /*         if ((tab[X][Y]=='X') | (tab[X][Y]=='O') | (tab[X][Y]=='o')| (tab[X][Y]=='#') || (Y<0) || (Y>=5) ) // non attaquable
                {
                   // printf("if 1");
                    system("cls");
                    printf("X c'est %d et Y c'est %d\n\n", X, Y);
                    affichage(tab, tabo, tablo);
                    printf ("Cette case n'est pas libre. Choisissez en une qui soit libre.\n");
                } */

                if (((tab[X][Y]==' ') | (tab[X][Y]=='x')) & (Y<5) & (Y>=0) & (X<5) & (X>=0) ) // attaquable
                {
            //        printf("if 2");
                    tab[X][Y]='X'; // met le X dans tab
                    checkautourx(tab, X, Y);
                    etirement(tablo,tab);
                    system("cls");
                    affichage(tabo, tablo);
                    u=1;
                    u2=1;
                }
                else
                {
                    if ((tab[X][Y]=='X') | (tab[X][Y]=='O') | (tab[X][Y]=='o')| (tab[X][Y]=='#') ) // non attaquable
                    {
                    // printf("if 1");
                        system("cls");
                        affichage(tabo, tablo);
                        if(iapasconfig==1)
                        {
                            printf("\nCette IA n'as pas encore ete configuree, vous jouez donc tout seul\n");
                        }
                        printf ("\nCette case n'est pas libre. Choisissez en une qui soit libre.\n");
                    }
                    else
                    {
                        system("cls");
                        affichage(tabo, tablo);
                        if(iapasconfig==1)
                        {
                            printf("\nCette IA n'as pas encore ete configuree, vous jouez donc tout seul\n");
                        }
                        printf ("\nCette case est hors champ. Choisissez une case qui soit dans le champ.\n");
                    }
                    u2=0;
                }
            }
            u=0;

        }

        else if (t==1) // IA (ordinateur)
        {
            if(modeia==1)
            {
                s=0;
                while((s<5) & (a==0))
                {
                    e=0;
                    while((e<5) & (a==0))
                    {
                        if(tab[s][e]==' ')
                        {
                            tab[s][e]='O';
                            checkautouro(tab, s, e);
                            etirement(tablo,tab);
                            system("cls");
                            affichage(tabo, tablo);
                            a=1;
                            O=s;
                            L=e;
                        }
                        e++;
                    }
                    s++;
                }
                a=0;
            }
            if(modeia==2)
            {
                iapasconfig=1;
                printf("\nCette IA n'as pas encore ete configuree, vous jouez donc tout seul\n");
            }


        }


        t=changementderole(t);
        z=0;
        z=jouabilite(tab, z);
    }
    printf ("\nFin de la partie.\n");
    whoisthewinner(tab);
}

