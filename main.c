#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//--- DECLARATION CONSTANTES ---
#define LIMITE 7

//--- DECLARATION TYPE STRUCTURE ---

typedef struct tPosition{
    int nLigne;
    int nColonne;
}tPosition;


//--- PROTOTYPES ---
void initTab(int mTableau[LIMITE][LIMITE]);
void affichage(const int mTableau[LIMITE][LIMITE]);
void droite (tPosition *pos);
void gauche (tPosition *pos);
void corriger (tPosition *pos);
void placer (int mTableau[LIMITE][LIMITE],const tPosition pos,int nCpt);
int vide (int mTableau[LIMITE][LIMITE],tPosition *pos);
void avancer (int mTableau[LIMITE][LIMITE],tPosition *pos,const int nCpt);



// --- PROGRAMME PRINCIPAL ---

//BUT : Afficher sur la console un tableau magique en 5x5 (ou plus si la constante LIMITE est modifiée (valeur impaire)) selon la méthode vue en cours
//ENTREE : /
//SORTIE : tableau de données rempli correctement

int main()
{
    //Déclaration des variables
    int mTableau[LIMITE][LIMITE];
    tPosition pos={2,3};
    int nCpt=0;

    // Programme
    initTab(mTableau);
   // affichage(mTableau);
   affichage(mTableau);


    //printf("Ligne = %d / Colonne = %d\n",pos.nLigne,pos.nColonne);
    //printf("Ligne = %d / Colonne = %d -  %d\n",pos.nLigne,pos.nColonne,mTableau[pos.nLigne][pos.nColonne]);
    mTableau[2][3]=1;
    for (nCpt=2;nCpt<((LIMITE-2)*(LIMITE-2)+1);nCpt++)
    {
        avancer(mTableau,&pos,nCpt);
        printf("\n");
        affichage(mTableau);
        //getch();
    }


    return 0;
}


//BUT : afficher le tableau de données sur la console
//ENTREE : tableau de données
//SORTIE : tableau de données

void affichage(const int mTableau[LIMITE][LIMITE])
{
    int nCptLigne=0;
    int nCptColonne=0;
    for (nCptLigne=1;nCptLigne<(LIMITE-1);nCptLigne++)
    {
        for (nCptColonne=1;nCptColonne<(LIMITE-1);nCptColonne++)
        {
            printf("[%d] ",mTableau[nCptLigne][nCptColonne]);
        }
        printf("\n");
    }
}

//BUT : initialiser à 0 les valeurs du tableau de données
//ENTREE : tableau de données
//SORTIE : tableau de données initialisé
void initTab(int mTableau[LIMITE][LIMITE])
{
    int nCptLigne=0;
    int nCptColonne=0;
    for (nCptLigne=0;nCptLigne<LIMITE;nCptLigne++)
    {
        for (nCptColonne=0;nCptColonne<LIMITE;nCptColonne++)
        {
            mTableau[nCptLigne][nCptColonne]=0;
        }
    }
}

//BUT : avancer la position d'une case à droite
//ENTREE : variable type tPosition
//SORTIE : variable type tPosition
void droite (tPosition *pos)
{
    pos->nColonne++;
}

//BUT : avancer la position d'une case en haut ET ensuite à gauche
//ENTREE : variable type tPosition
//SORTIE : variable type tPosition
void gauche (tPosition *pos)
{
    pos->nLigne-=1;
    pos->nColonne-=1;
}

//BUT : permettre de corriger la position du pointeur : s'il sort du tableau il est affecté à l'opposé correspondant
//ENTREE : variable type tPosition
//SORTIE : variable type tPosition
void corriger (tPosition *pos)
{
    if (pos->nLigne>(LIMITE-2))
    {
        pos->nLigne-=(LIMITE-2);
    }
    if (pos->nColonne>(LIMITE-2))
    {
        pos->nColonne-=(LIMITE-2);
    }
    if (pos->nLigne<1)
    {
        pos->nLigne+=(LIMITE-2);
    }
    if (pos->nColonne<1)
    {
        pos->nColonne+=(LIMITE-2);
    }
}

//BUT : attribuer la valeur du compteur à la case du tableau correspondant à la position pointée
//ENTREE : variable type tPosition, compteur, Tableau de valeurs
//SORTIE : Tableau de valeurs modifié
void placer (int mTableau[LIMITE][LIMITE],const tPosition pos,int nCpt)
{
    mTableau[pos.nLigne][pos.nColonne]=nCpt;
    //printf("Procedure PLACER - X = %d / Y = %d - %d\n nCpt = %d",pos.nLigne,pos.nColonne,mTableau[pos.nLigne][pos.nColonne],nCpt);
}

//BUT : obtenir l'information suivante : la case du tableau correspondante au pointeur est-elle vide ou non ?
//ENTREE : variable type tPosition et Tableau de données
//SORTIE : booléen : 1 ou 0
int vide (int mTableau[LIMITE][LIMITE],tPosition *pos)
{
    //printf("VIDE = %d\n",mTableau[pos->nLigne][pos->nColonne]);
    if(mTableau[pos->nLigne][pos->nColonne]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//BUT : gérer le déplacement du pointeur puis l'affectation de la valeur au sein du tableau
//ENTREE : variable type tPosition , tableau de données, compteur
//SORTIE : variable type tPosition modifiée, tableau de données modifié
void avancer (int mTableau[LIMITE][LIMITE],tPosition *pos,int const nCpt)
{
    pos->nLigne-=1;
    droite(&*pos);
    corriger(&*pos);
    if (vide(mTableau,pos))
    {
        placer(mTableau,*pos,nCpt);
    }
    else
    {
        gauche(&*pos);
        corriger(&*pos);
        placer(mTableau,*pos,nCpt);
    }

}
