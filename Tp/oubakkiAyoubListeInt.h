typedef struct maillon
{
    int val;
    struct maillon *p_suiv;
} maillon_int;

maillon_int *init_elt();
maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt);
void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt);
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt);
void parcourir(maillon_int *p_tete);
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt);
void inserer2(maillon_int **prem, maillon_int *e);
void supprimer_debut(maillon_int **prem);
void detruire_liste(maillon_int **prem);
void detruire_liste2(maillon_int **prem);
void sauver_liste(maillon_int *prem);
maillon_int *load_liste();