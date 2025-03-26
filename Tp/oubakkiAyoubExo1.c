/*
    Documentation section
    @Project Tp2 Ex1
    @Author Oubakki ayoub
    @Created 20250325
    @Program Description,Utilisation,  ré-utilisation,  structuration  d’un  code 
manipulant/implémentant d’une liste chaînée d’entiers1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "oubakkiAyoubListeInt.c"
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
           "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
           "4 Supprimer l'élément de tête\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

int main()
{
    maillon_int *premier = NULL;
    maillon_int *nouveau;
    maillon_int **prem2=NULL;
    maillon_int **prem3=NULL;
    int fin = 0;
    int i, nb,taille;
    int val;

    srand((unsigned)time(NULL));
    while (!fin)
    {
        i = menu();
        switch (i)
        {

        case 1: // Creer une liste de taille aleatoire
                taille=rand()%21;
                for(int i=0;i<taille;i++){
                    nouveau=init_elt();
                    premier=inserer1(premier,nouveau);
                }
                parcourir(premier);
            break;

        case 2: // Ajouter
            nouveau=init_elt();
            premier=ajout_tete_v1(premier,nouveau);
            parcourir(premier);
            // prem3=&premier;
            // ajout_tete_v2(prem3,nouveau);

            break;

        case 3: // Inserer (ordre croissant)
            nouveau=init_elt();
            premier=inserer1(premier,nouveau);
            parcourir(premier);
            break;

        case 4: // Supprimer debut:
            prem2=&premier;
            supprimer_debut(prem2);
            parcourir(premier);   
            break;

        case 5: // Supprimer un maillon d'une valeur donnee
            // Fonction à écrire...
            
            // printf("Entrer la valeur");
            // scanf("%d",&val);
            // supprime_elt(&premier,val);
            // parcourir(premier);   
            break;

        case 6: // detruire liste
            prem2=&premier;
            detruire_liste(prem2);
            parcourir(premier);

            break;

        case 7: // Sauver liste
            sauver_liste(premier);
            parcourir(premier);
            break;

        case 8: // Charger liste
            premier=load_liste();
            parcourir(premier);
            break;
        case 9: // Charger liste
            parcourir(premier);
            break;


        default:

            break;
        }
    }

    return 0;
}