#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

float poly(cell *T,float x)
{
    int i=0;
    float r=0;
    cell *p=T;
    while (p)
    {
        r+=(p->val)*pow(x,i);
        i++;
        p=p->next;
    }
    return r;
}

int main()
{
    int n,v,i;
    float x,p;
    cell *liste=NULL,*nouv=NULL;
    do
    {
        printf("saisir le degre de polynome (positif) : ");
        scanf("%d",&n);
    }while (n<=0);
    for (i=0;i<=n;i++)
    {
        printf("\nSaisir le coefficient de degre %d de polynome : ",n-i);
        scanf("%d",&v);
        nouv=init(v);
        liste=ajout_tete(liste,nouv);
    }
    printf("\nsaisir la valeur x pour calculer le polynome : ");
    scanf("%f",&x);
    p=poly(liste,x);
    printf("\nP(%f) = %f",x,p);
    return 0;
}
