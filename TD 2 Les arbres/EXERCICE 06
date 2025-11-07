#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
    int val;
    struct arbre* FG;
    struct arbre* FD;
}arbre;

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

arbre* arb_inf(arbre* Ar, int e)
{
    if (!Ar)
        return NULL;
    if (Ar->val >=e)
        return arb_inf(Ar->FG, e);
    else
    {
        arbre* nouv= (arbre*)malloc(sizeof(arbre));
        nouv->val=Ar->val;
        nouv->FG=Ar->FG;
        nouv->FD=arb_inf(Ar->FD, e);
        return nouv;
    }
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

int main()
{
    int n,choix,e;
    arbre *arb=NULL, *ar_e=NULL;
    do
    {
        printf("donner un nombre : ");
        scanf("%d",&n);
        arb=InserValeur(arb,n);
        printf("Voulez vous inserer un autre entier?\nTapez un : ");
        scanf("%d",&choix);
    }while(choix==1);
    printf("\nsaisir e : ");
    scanf("%d",&e);
    ar_e=arb_inf(arb,e);
    afficher_infixe(ar_e);
    return 0;
}
