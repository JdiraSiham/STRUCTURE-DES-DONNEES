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
            Ar->FG=InserValeur(Ar->FG, v);
        else
            Ar->FD=InserValeur(Ar->FD, v);
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

int min_arbre(arbre *arb)
{
    arbre *a=NULL;
    for(a=arb;a->FG;a=a->FG);
    return a->val;
}

arbre *supp_racine(arbre *a)
{
    if (!a->FG&&!a->FD)
    {
        free (a);
        return NULL;
    }
    arbre* r =NULL;
    if (!a->FG)
    {
        r=a->FD;
        free(a);
        return r;
    }
    if (!a->FD)
    {
        r=a->FG;
        free(a);
        return r;
    }
    arbre *p=a,*min_g=a->FG;
    while (min_g->FG)
    {
        p= min_g;
        min_g= min_g->FG;
    }
    a->val=min_g->val;
    if (p==a)
        p->FG=min_g->FD;
    else
        p->FG=min_g->FD;
    free(min_g);
    return a;
}

arbre *supp_e(arbre *a,int e)
{
    if (e<a->val)
        a->FG=supp_e(a->FG,e);
    else if (e>a->val)
        a->FD=supp_e(a->FD,e);
    else
        a=supp_racine(a);
    return a;
}

int main()
{
    int n,choix,e;
    arbre *arb=NULL;
    do
    {
        printf("donner un nombre : ");
        scanf("%d",&n);
        arb=InserValeur(arb,n);
        printf("Voulez vous inserer un autre entier?\nTapez un : ");
        scanf("%d",&choix);
    }while(choix==1);
    printf("la plus petite valeur de cet arbre est : %d \n",min_arbre(arb));
    arb =supp_racine(arb);
    printf("\napres la suppression de la racine : \n");
    afficher_infixe(arb);
    printf("\nsaisir l'element a supprimer : ");
    scanf("%d",&e);
    arb=supp_e(arb,e);
    printf("\napres la suppression de %d : \n",e);
    afficher_infixe(arb);
    return 0;
}
