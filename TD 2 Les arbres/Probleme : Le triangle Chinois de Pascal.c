#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
    int val;
    struct arbre* FG;
    struct arbre* FD;
}arbre;

arbre *InserValeur(arbre *Ar, int v)
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

int puissance(int x,int n)
{
    int puiss=1,i;
    for (i=0;i<n;i++)
        puiss*=x;
    return puiss;
}

void trianglePascal(int n,int triangle[][n+1])
{
    int i,k;
    for(i=0;i<=n;i++)
    {
        triangle[i][0]=1;
        triangle[i][i]=1;
        for(k=1;k<i;k++)
            triangle[i][k]=triangle[i-1][k-1]+triangle[i-1][k];
    }
}

void afficherTriangle(int n)
{
    int triangle[n+1][n+1],i,j;
    trianglePascal(n,triangle);
    printf("Triangle de Pascal (n=%d) :\n", n);
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=i;j++)
            printf("%d ",triangle[i][j]);
        printf("\n");
    }
}

int calculerBinome(int n,int x,int y)
{
    int triangle[n+1][n+1],res=0,k;
    trianglePascal(n,triangle);
    for(k=0;k<=n;k++)
        res+=triangle[n][k]*puissance(x,k)*puissance(y,n-k);
    return res;
}

int main()
{
    int n,x,y,resultat;
    printf("saisir x : ");
    scanf("%d",&x);
    printf("saisir y : ");
    scanf("%d",&y);
    printf("saisir n : ");
    scanf("%d",&n);
    resultat=calculerBinome(n,x,y);
    printf("(%d + %d)^%d = %d\n",x,y,n,resultat);
    afficherTriangle(n);
    return 0;
}
