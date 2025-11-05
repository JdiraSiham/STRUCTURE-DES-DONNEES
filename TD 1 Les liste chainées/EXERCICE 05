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

cell *supp_occ(cell *T, int x) {
    cell *p = T;
    cell *q = NULL;
    while (p != NULL) {
        if (p->val == x) {
            cell *tmp = p;
            if (q == NULL)
            {
                T = p->next;
                p = T;
            }
            else
            {
                q->next = p->next;
                p = p->next;
            }
            free(tmp);
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return T;
}

cell * supp_k_occ(cell *T,int x,int k)
{
    cell *p = T,*q = NULL;
    int i=0;
    while (p != NULL)
    {
        if (p->val == x)
        {
            i++;
            if (i>k)
            {

                cell *tmp = p;
                if (q == NULL)
                    T = p->next;
                else
                    q->next = p->next;
                p = p->next;
                free(tmp);
                continue;
            }
        }
            q = p;
            p = p->next;
    }
    return T;
}

cell * supp_occ_sauf_1(cell *T,int x)
{
    cell *p = T;
    while (p!=NULL)
    {
        T=supp_k_occ(T,p->val,1);
        p=p->next;
    }
    return T;
}


int main()
{
    int n,v,i,x,k,c;
    cell *liste=NULL,*nouv=NULL;
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
    printf("saisir un nombre pour supprimer occurance : ");
    scanf("%d",&x);
    printf("Saisir 1 pour supprimer toutes les occurrences");
    printf("\nSaisir 2 pour laisser que les k premières occurrences de cet élément et supprimer les suivantes");
    printf("\nSaisir 3 pour laisser que sa premiere occurrences");
    do
    {
        printf("\nSaisir votre choix : ");
        scanf("%d",&c);
    }while(c!=1 && c!=2 &&c!=3);
    if (c==1)
    {
        liste=supp_occ(liste,x);
        printf("la liste apres suppresion des occurances de %d est : \n",x);
        print(liste);
    }
    else if (c==2)
    {
        printf("saisir k : ");
        scanf("%d",&k);
        liste=supp_k_occ(liste,x,k);
        printf("la liste apres suppresion des %d occurances de %d est : \n",k,x);
        print(liste);
    }
    else if (c==3)
    {
        liste=supp_occ_sauf_1(liste,x);
        printf("la liste apres suppresion des occurances de %d sauf la premiere est : \n",x);
        print(liste);
    }
    return 0;
}
