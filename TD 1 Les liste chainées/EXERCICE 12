#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int val;
    struct cel *next;
}pile;

pile *nouvellePile()
{
    return NULL;
}

int estPileVide(pile *p)
{
    return p==NULL;
}

pile *empiler(int v,pile *pp)
{
    pile *nouv=(pile*)malloc(sizeof(pile));
    nouv->val=v;
    nouv->next=pp;
    return nouv;
}

int depiler(int *v,pile **pp)
{
    if (*pp==NULL)
        return 0;
    *v=(*pp)->val;
    pile *tmp=*pp;
    *pp=(*pp)->next;
    free(tmp);
    return 1;
}

int somme(int n) {
    pile *p=nouvellePile();
    int s=0,i,v;
    for (i=n;i>=1;i--)
        p=empiler(i, p);
    while (!estPileVide(p))
    {
        depiler(&v,&p);
        s+=v;
    }
    return s;
}

int main() {
    int n,s;
    printf("saisir n : ");
    scanf("%d",&n);
    s=somme(n);
    printf("somme de 1 a %d = %d",n,s);
    return 0;
}
