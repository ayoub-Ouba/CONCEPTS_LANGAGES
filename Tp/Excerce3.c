/*
    Documentation section
    @Project Tp2 Ex3
    @Author Oubakki ayoub
    @Created 20250325
    @Program Description,Gestion des horaires de trains.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct horaire {
    int heurDepart;  
    int minuteDepart;  
    int heurArriver; 
    int minutArriver; 
} horaire;

typedef struct system_horaire {
    char ville_dep[20];   
    char ville_arr[20];   
    int distance;        
    horaire horaires_tr[2]; 
    struct system_horaire* suivant; 
} system_horaire;

// Fonction de création du système horaire
system_horaire* creerSystem_horaire(system_horaire* tete,char* ville_dp, char* ville_arr, int distance, int h_dep,int m_dep, int h_arv, int m_arv) {
    system_horaire *nv = malloc(sizeof(system_horaire));

    // Vérifier que l'allocation a réussi
    if (nv == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }

 
    nv->distance = distance;

    //copy maximum des caracters de ville_dp dans nv->ville_dep
    strncpy(nv->ville_dep, ville_dp, sizeof(nv->ville_dep) - 1);
    // on ajoute '\0' pour terminer  la chaine copiée 
    nv->ville_dep[sizeof(nv->ville_dep) - 1] = '\0'; 

    strncpy(nv->ville_arr, ville_arr, sizeof(nv->ville_arr) - 1);
    nv->ville_arr[sizeof(nv->ville_arr) - 1] = '\0'; 
    nv->horaires_tr[0].heurDepart=h_dep;
    nv->horaires_tr[0].minuteDepart=m_dep;
    nv->horaires_tr[0].heurArriver=h_arv;
    nv->horaires_tr[0].minutArriver=m_arv; 
    nv->suivant=tete;
   tete=nv;
   return tete;
}

void ajouter_heures(system_horaire* tete, char* ville_dep,char* ville_arr,int h_dep,int m_dep, int h_arv, int m_arv){
    if(tete==NULL){
        printf("liste vide");
    }else{
        while(tete!=NULL){
            if(strcmp(tete->ville_dep,ville_dep)==0 && strcmp(tete->ville_arr,ville_arr)==0){
                tete->horaires_tr[1].heurDepart=h_dep;
                tete->horaires_tr[1].minuteDepart=m_dep;
                tete->horaires_tr[1].heurArriver=h_arv;
                tete->horaires_tr[1].minutArriver=m_arv;
                return;
            }
            tete=tete->suivant;
        }
    }

}


void afficher(system_horaire* tete, char* ville_dep){
    if(tete==NULL){
        printf("liste vide");
    }else{
        while(tete!=NULL){
            if(strcmp(tete->ville_dep,ville_dep)==0){
                printf("ville depart : %s, ville d'arriver : %s, distance: %d",
                tete->ville_dep,tete->ville_arr,tete->distance);
                
                for(int i=0;i<2;i++){
                    
                    printf(" heure de depart : %dh%d, heure d'arriver :%dh%d\n",
                        tete->horaires_tr[i].heurDepart,tete->horaires_tr[i].minuteDepart,tete->horaires_tr[i].heurArriver,tete->horaires_tr[i].minutArriver);
                   
                  
                }
             }
            tete=tete->suivant;
        }
    }

}

void moyenne_pluseleve(system_horaire* tete, char* ville_dep,char* ville_arr){
    if(tete==NULL){
        printf("liste vide");
    }else{
        int h_d = 0, m_d = 0, h_ar = 0, m_ar = 0, distance = 0;
        int meilleure_duree = 100000;
        while(tete!=NULL){
            if(strcmp(tete->ville_dep,ville_dep)==0 && strcmp(tete->ville_arr,ville_arr)==0){
               
                int depart_total = tete->horaires_tr[0].heurDepart * 60 + tete->horaires_tr[0].minuteDepart;
                int arrivee_total = tete->horaires_tr[0].heurArriver * 60 + tete->horaires_tr[0].minutArriver;
              
                int duree = arrivee_total - depart_total; // Durée du trajet en minutes
                if (duree < meilleure_duree) {
                    meilleure_duree = duree;
                    h_d = tete->horaires_tr[0].heurDepart;
                    m_d = tete->horaires_tr[0].minuteDepart;
                    h_ar = tete->horaires_tr[0].heurArriver;
                    m_ar = tete->horaires_tr[0].minutArriver;
                    distance = tete->distance;
                }
               
            }
            tete=tete->suivant;
        }
        if (meilleure_duree == 100000) {
            printf("Aucun trajet trouve entre %s et %s.\n", ville_dep, ville_arr);
        } else {
            printf("Trajet le plus court trouve : \n");
            printf("Ville de depart : %s, Ville d'arrivee : %s, Distance : %d km\n", ville_dep, ville_arr, distance);
            printf("Heure de depart : %02dh%02d, Heure d'arrivee : %02dh%02d\n", h_d, m_d, h_ar, m_ar);
        }
    }

}




int main() {
    // Exemple d'utilisation
    system_horaire* tete=NULL;
    tete = creerSystem_horaire(tete,"Paris", "Lyon", 470, 9 ,00, 11,00);

    tete = creerSystem_horaire(tete,"Paris", "Lyon", 450, 11,50, 17,00);
    ajouter_heures(tete,"Pars", "Marseille",8,50, 11,00);
    // Afficher les informations du trajet
     afficher(tete,"Pars");
     moyenne_pluseleve(tete,"Paris", "Lyon");

    return 0;
}
