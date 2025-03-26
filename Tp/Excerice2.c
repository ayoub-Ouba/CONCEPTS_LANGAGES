/*
    Documentation section
    @Project Tp2 Ex2
    @Author Oubakki ayoub
    @Created 20250325
    @Program Description,Structure de données Pile [d’entiers].
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdbool.h> 
//liste chainée
//parce que liste chainée  évite le gaspillage de mémoire et Avec une liste chaînée, on n'alloue que ce qui est nécessaire .
//aussi pour bien comprendre la liste chainée
typedef struct pile {
    int val;
    struct pile *suivant;
}pile_int;

bool estvide(pile_int *tete){
    if(tete==NULL){
        return true;
    }
    return false;
};

pile_int * empiler(pile_int *tete,int val){
    pile_int * nv_val=malloc(sizeof(pile_int));
    nv_val->val =val;
    nv_val->suivant = NULL;

    // Cas où la liste est vide
    if (tete == NULL) {
        tete = nv_val;
        return tete;
    }

    // Parcourir la liste jusqu'au dernier élément
    pile_int* temp = tete;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }

    temp->suivant = nv_val;
    return tete;
}

int sommet(pile_int *tete){
    if(tete==NULL){
        printf("liste vide");
        
    }else{
        bool fin =false;
        int c=0;
        while (fin==false)
        {
            if(tete->suivant==NULL){
                fin=true;
            }
            c=c+1;
            tete=tete->suivant;
        }
        return c;
    }
    return 0;
}

pile_int * enlever(pile_int *tete){
    if(tete==NULL){
        printf("liste vide");
        return NULL;
    }
    pile_int * courant=tete;
    // supprimer si la taille de tableau = 1
    if(courant->suivant==NULL){
        free(courant);
        return NULL;
    }

    while(courant->suivant->suivant!=NULL){
        courant=courant->suivant;
    }
    free(courant->suivant);
    courant->suivant=NULL;
    return tete;

}

void afficher(pile_int *tete){
    if(tete==NULL){
        printf("liste vide");
    }else{
        while (tete!=NULL)
        {
            printf(" %d --> ",tete->val);
            tete=tete->suivant;
        }
        printf("Null \n");
    }
}

pile_int* reverseList(pile_int* head) {
    pile_int* prev = NULL;        
    pile_int* current = head;     
    pile_int* next = NULL;       

    while (current != NULL) { // Parcours de la liste
        next = current->suivant;  // 1. Sauvegarde du nœud suivant
        current->suivant = prev;  // 2. Inversion du lien : current pointe vers prev
        prev = current;        // 3. Avancer prev pour suivre current
        current = next; // 4. Avancer current pour continuer le parcours
        
    }

    return prev; 
}

int main(){
    pile_int *tete = NULL;
    pile_int *nouveau;
    
    printf("Notre pile est %d \n ",estvide(tete));
    tete=empiler(tete,15);
    tete=empiler(tete,20);
    tete=empiler(tete,01);

    printf("Notre pile est %d \n ",estvide(tete));
    afficher(tete);

    printf("le sommet est %d \n ",sommet(tete));
    printf("enlever \n");
    tete=enlever(tete);
    printf("le sommet est %d \n ",sommet(tete));

    afficher(tete);
    tete=reverseList(tete);
    afficher(tete);
    

}