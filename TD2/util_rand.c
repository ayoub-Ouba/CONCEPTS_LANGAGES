/*
    Documentation section
    @Project 
    @Author Oubakki ayoub
    @Created 20250103
    @Program Description, Program to compute the area of a cirlce
*/
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "util_rand.h"

int fonction_aletoire_2(int seul_h){
    int num=  rand() % seul_h + 1;
    return num;
}


bool verifier_vals_aleatoire(int* tabl){
    
    if (sizeof(tabl)<2){return true;}
    else{
        for(int i=0;i<sizeof(tabl);i++){
      
            for(int j=i;j<sizeof(tabl)-1;j++){
            
                if(*(tabl+i)==*(tabl+j+1)){
                    return true;
                }
            }
        }
        return false;
    }
}

void fonction_Q3(int* t){
    for(int i=0;i<20;i++){
        *(t+i)=fonction_aletoire_2(5);
        printf("I %d => %d \n",i, *(t+i));
    }
    if(verifier_vals_aleatoire(t)){
        for(int i=0;i<20;i++){
            int c=0;
            // je compte le nombre de *(t+i) dans le reste de tableau (à partire de i)
            for(int j=i;j<19;j++){
                if(*(t+i)==*(t+j+1) && *(t+j+1)!=-1){
                    //j'ai fais cette ligne pour éviter de calculer le nombre de répetition de nombre que le programe déja calculer   
                    *(t+j+1)=-1;
                    c++;
                }
            }
            if(c>0){
                //j'ai ajouté 1 parce que l'algorithme qui calcul le nombre de repétition ne calcul pas la premier valeur il calcule que les occurrences
                c=c+1;
                printf("les nombres des occurrences de %d est %d // ",*(t+i),c);
                //Il doit changer le type de c parce que int sur int equal float sinon resultat toujours 0 
                float prcn= (float)c / 20 *100 ;
                printf("le pourcentage est %.f \n",prcn);
            }
        }
    }

}

int main(int argc, char const *argv[]){
    srand(time(NULL));
    // int val;
    // int* tabl;
    // int val_func_verf=1;
    // int conteur=0;
    // int somme;
    
    // printf("Avec combien de des voulez vous jouer ?\n");
    // printf("Taper 1, 2, 3 ou 4 :");
    // scanf("%d",&val);
    // tabl=malloc(val*sizeof(int));
    // printf("vous avez choisi %d de(s) \n",val);
   
    // while(val_func_verf==1){
    //     if(conteur>0){
    //         printf("Des identiques relances...\n");
    //     }
    //     somme=0;
    //     for(int i=0;i<val;i++){
    //         int val_aleatoire=fonction_aletoire_2(6);
    //         *(tabl+i)=val_aleatoire;
    //         somme=somme+*(tabl+i);
    //          printf("De %d : %d \n",i,val_aleatoire);
    //     }
    //     val_func_verf=verifier_vals_aleatoire(tabl);
    //     conteur++;
    // }
    // printf("la somme des %d des lances est de %d , le seuil etait de %d \n",val,somme,6*val);
    // int score_maximal=(6*val);
    // if(somme>=score_maximal){
    //     printf("le score supérieur de %d au seuil\n",somme-score_maximal);
    //     printf("Felicitation,Vous avez gagne !");

    // }else{printf("le score inferieur de %d au seuil \n",score_maximal-somme);
    //     printf("Desole,Vous avez perdu !");}
    int* t;
    t=malloc(20*sizeof(int));
    fonction_Q3(t);
    


    
return 0;

}