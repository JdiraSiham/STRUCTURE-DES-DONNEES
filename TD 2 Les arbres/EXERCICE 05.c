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

typedef struct cel
{
    int val;
    struct cel* next;
} cell;

cell *init(int v)
{
    cell *nouv=NULL;
    nouv=(cell*)malloc(sizeof(cell));
    nouv->val=v;
    nouv->next=NULL;
    return nouv;
}

cell * ajout_tete(cell *T, cell *n)
{
    n->next=T;
    T=n;
    return T;
}

void liste_non_div(arbre *a,arbre *p,cell **tete)
{
    if (a==NULL)
        return;
    if (p==NULL||(a->val%p->val!=0&& p->val %a->val !=0))
    {
        cell *n=init(a->val);
        *tete = ajout_tete(*tete,n);
    }
    liste_non_div(a->FG, a,tete);
    liste_non_div(a->FD,a,tete);
}

int main() {
    int n,choix;
    arbre *arb=NULL;
    cell *tete = NULL;
    do {
        printf("saisir un nombre : ");
        scanf("%d",&n);
        arb=InserValeur(arb,n);
        printf("Voulez vous inserer un autre entier?\nTapez un : ");
        scanf("%d",&choix);
    }while(choix==1);
    liste_non_div(arb,NULL,&tete);
    printf("les elements non divisibles par leur parent : ");
    for (cell *c=tete;c!= NULL;c=c->next)
        printf("%d ",c->val);
    return 0;
}
