#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
    int val;
    struct arbre* FG;
    struct arbre* FD;
} arbre;

arbre* empty()
{
    return NULL;
}

int is_empty(arbre* a)
{
    return a==NULL;
}

arbre* sag(arbre* a)
{
    if (is_empty(a))
        return NULL;
    return a->FG;
}

arbre* sad(arbre* a)
{
    if (is_empty(a))
        return NULL;
    return a->FD;
}

int taille(arbre* a)
{
    if (is_empty(a))
        return 0;
    return 1+taille(a->FG)+taille(a->FD);
}

int hauteur(arbre* a)
{
    if (is_empty(a))
        return 0;
    int hg=hauteur(a->FG);
    int hd=hauteur(a->FD);
    if (hg>hd)
        return 1+hg;
    else
        return 1+hd;
}

int est_filiforme(arbre* a)
{
    if (is_empty(a))
        return 1;
    if (!is_empty(a->FG)&&!is_empty(a->FD))
        return 0;
    return est_filiforme(a->FG)&&est_filiforme(a->FD);
}

arbre* peigne(int n)
{
    if (n <= 0)
        return NULL;
    arbre* a = (arbre*)malloc(sizeof(arbre));
    a->val = n;
    a->FD = NULL;
    a->FG = peigne(n - 1);
    return a;
}

int main()
{
    arbre* a = peigne(3);
    if (est_filiforme(a))
    {
        printf("peigne(3) est filiforme  \n");
        if (taille(a)==hauteur(a))
            printf("on a taille de a est : %d et hauteur de a est : %d donc pour tout arbre filiforme t on a l’egalite taille(t) = hauteur(t)",taille(a),hauteur(a));
        else
            printf("on a taille de a est : %d et hauteur de a est : %d donc pas l’egalite taille(t) = hauteur(t) pour les arbre filiforme",taille(a),hauteur(a));
    }
    else
        printf("peigne(3) n'est pas filiforme");
    return 0;
}
