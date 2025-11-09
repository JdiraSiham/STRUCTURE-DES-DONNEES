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

void som(arbre* a, int* sp, int* np, int* sn, int* nn)
{
    if (!a)
        return;
    if (a->val >= 0)
    {
        *sp+=a->val;
        (*np)++;
    }
    else
    {
        *sn+=a->val;
        (*nn)++;
    }
    som(a->FG,sp,np,sn,nn);
    som(a->FD,sp,np,sn,nn);
}

int main()
{
    int n,choix,np=0,nn=0,sp=0,sn=0;
    arbre *arb=NULL;
    float moy_pos,moy_neg;
    do
    {
        printf("donner un nombre : ");
        scanf("%d",&n);
        arb=InserValeur(arb,n);
        printf("Voulez vous inserer un autre entier?\nTapez un : ");
        scanf("%d",&choix);
    }while(choix==1);
        som(arb,&sp,&np,&sn,&nn);
    if (np!=0)
        moy_pos=(float)sp/np;
    else
        moy_pos=0;
    if (nn!=0)
        moy_neg=(float)sn/nn;
    else
        moy_neg=0;
    printf("la moyenne des elements positifs est : %f . et la moyenne des elements negatifs est : %f",moy_pos,moy_neg);
    return 0;
}
