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

cell *concat(cell *T1,cell *T2)
{
    if (T1==NULL)
        return T2;
    cell *p=T1;
    for(p=T1;p->next!=NULL;p=p->next);
    p->next=T2;
    return T1;
}


int main()
{
    int n,m,v1,v2,i;
    cell *liste1=NULL,*liste2=NULL,*nouv1=NULL,*nouv2=NULL;
    do
    {
        printf("saisir la taille de la liste 1 : ");
        scanf("%d",&n);
    }while (n<=0);
    for (i=0;i<n;i++)
    {
        printf("\nSaisir l'element %d de la liste 1 : ",i);
        scanf("%d",&v1);
        nouv1=init(v1);
        liste1=ajout_tete(liste1,nouv1);
    }
    print(liste1);
    do
    {
        printf("saisir la taille de la liste 2 : ");
        scanf("%d",&m);
    }while (m<=0);
    for (i=0;i<m;i++)
    {
        printf("\nSaisir l'element %d de la liste 2 : ",i);
        scanf("%d",&v2);
        nouv2=init(v2);
        liste2=ajout_tete(liste2,nouv2);
    }
    print(liste2);
    printf("\nles deux liste concatene : \n");
    liste1=concat(liste1,liste2);
    print(liste1);
    return 0;
}
