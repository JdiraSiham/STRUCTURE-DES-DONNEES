#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int val;
    struct cel *next;
}cell;

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

void print(cell *T)
{
    cell *p=NULL;
    for (p=T;p;p=p->next)
    {
        printf("%d \n",p->val);
    }
}

cell *positif(cell *T)
{
    cell *p=NULL,*nouv=NULL,*L=NULL;
    p=T;
    while(p)
    {
        if (p->val >= 0)
        {
            nouv=init(p->val);
            L=ajout_tete(L,nouv);
        }
        p=p->next;
    }
    return L;
}
cell *negatif(cell *T)
{
    cell *p=NULL,*nouv=NULL,*L=NULL;
    p=T;
    while(p)
    {
        if (p->val < 0)
        {
            nouv=init(p->val);
            L=ajout_tete(L,nouv);
        }
        p=p->next;
    }
    return L;
}

int main()
{
    int n,v,i;
    cell *liste=NULL,*nouv=NULL,*l1=NULL,*l2=NULL;
    do
    {
        printf("saisir la taille de la liste (positif) : ");
        scanf("%d",&n);
    }while (n<=0);
    for (i=0;i<n;i++)
    {
        printf("\nSaisir l'element %d de la liste : ",i);
        scanf("%d",&v);
        nouv=init(v);
        liste=ajout_tete(liste,nouv);
    }
    print(liste);
    printf("la liste des entiers positifs est : \n");
    l1=positif(liste);
    print(l1);
    printf("la liste des entiers negatifs est : \n");
    l2=negatif(liste);
    print(l2);
    return 0;
}
