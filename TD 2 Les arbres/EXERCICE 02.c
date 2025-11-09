#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
    int val;
    struct arbre* FG;
    struct arbre* FD;
} arbre;

arbre *InserValeur (arbre *Ar, int v)
{
    if (Ar!=NULL)
    {
        if (Ar->val > v)
            Ar->FG=InserValeur (Ar->FG, v);
        else
            Ar->FD=InserValeur (Ar->FD, v);
    }
    else
    {
        Ar=(arbre *)malloc(sizeof (arbre));
        Ar->val=v;
        Ar->FD=NULL;
        Ar->FG=NULL;
    }
    return Ar;
}

void afficher_infixe(arbre *Ar)
{
    if (Ar != NULL)
    {
        afficher_infixe(Ar->FG);
        printf("%d ", Ar->val);
        afficher_infixe(Ar->FD);
    }
}

void afficher_prefixe(arbre *Ar)
{
    if (Ar != NULL)
    {
        printf("%d ", Ar->val);
        afficher_prefixe(Ar->FG);
        afficher_prefixe(Ar->FD);
    }
}

void afficher_postfixe(arbre *Ar)
{
    if (Ar != NULL)
    {
        afficher_postfixe(Ar->FG);
        afficher_postfixe(Ar->FD);
        printf("%d ", Ar->val);
    }
}

int main()
{
    int T[12]={4,2,0,1,3,20,12,7,6,15,13,14};
    int n=12,i;
    arbre *arb=NULL;
    for (i=0;i<12;i++)
    {
        arb=InserValeur(arb,T[i]);
    }
    printf("l'affichage de l'arbre dans l'ordre de parcours prefixe : \n");
    afficher_prefixe(arb);
    printf("\nl'affichage de l'arbre dans l'ordre de parcours infixe : \n");
    afficher_infixe(arb);
    printf("\nl'affichage de l'arbre dans l'ordre de parcours postfixe : \n");
    afficher_postfixe(arb);
    return 0;
}
