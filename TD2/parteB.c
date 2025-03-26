/*
    Documentation section
    @Project 
    @Author Oubakki ayoub
    @Created 20250103
    @Program Description,  Pointeurs 
*/
#include<stdio.h>
#include <stdlib.h>
#include"util_rand.h"

//Function prototype declaration section

int summArray(int *t,int taille,int* computed_sum){
    if(t==NULL){
        return -1;
    }else{
        int somme=0;
        for(int i=0;i<taille;i++){
            somme=somme+*(t+i);
        }
        *computed_sum=somme;
        return 0;
    }
}
int searchArray(int* t,int taille,int element,int **emplacement){
    for(int i=0;i<taille;i++){
        if(*(t+i)==element){
           *emplacement=t+i;
            return 0;
        }
    }
    return -1;
}

int fois_deux(int i){  
    return i*2; 
   }
void appliquerATableau(int f(int,int), int* t, int n){ 
    for (int i=0; i<n; i++){t[i]=f(t[i],1);} 
}

void fct_mi_max(int* t,int taille,int** max){
    int max_val = t[0];
    for (int i=1; i<taille; i++){
        if(*(t+i)>max_val){
            *max=(t+i);
        
        }
    } 

}
//la fonction qui appelle à la fonction fois_deux
//void appliquerATableau(int f(int), int* t, int n){ 
//     for (int i=0; i<n; i++){t[i]=f(t[i]);} 
// }

void appliquerATableauPurPointeurs(int f(int), int* t, int n){ 
    for (int i=0; i<n; i++){*(t+i)=f(t[i]);} 
}
int f1(int element,int param){
    return element+param;

}

int superieur(int a,int b){
    if(a>b)return 1;
    else if(a==b)return 0;
    else return -1;
}

int inferieur(int a,int b){
    if(a<b)return 1;
    else if(a==b)return 0;
    else return -1;
}

void tri_proc(int* t,int n,int f(int,int)){
    int i_max_min;
    for(int i=0;i<n-1;i++){
        i_max_min=i;
        for (int j=i+1;j<n;j++){ 
            if(f(t[j],t[i_max_min])==1){
                
                i_max_min=j;
            }
            
        }
       
        if(i_max_min!=i){
            
            int temp=t[i];
            t[i]=t[i_max_min];
            t[i_max_min]=temp;
        }
    }
}

void fuc_stack_overflow(int n){
    int t[10000000]={0};  
    printf("Premier élément : %d\n", t[0]);
    fuc_stack_overflow(n+1);
}

//Main function

int main(int argc, char const *argv[]){
//Q2
    //test d'un tableau statique
    //    int t[5]={1,2,3,4,5};
    //    int* p=t;
    //    int somme=0;
    //    printf("la somme avant l'appel de la fonction: %d\n",somme);
    //    summArray(p,5,&somme);
    //    printf("la somme aprés l'appel de la fonction :%d \n",somme);

    //test d'un tableau dynamique

    // int *t;
    // t=malloc(5*sizeof(int));
    // for (int i=0;i<=sizeof(t);i++){
    //     *(t+i)=i+5;
    // }
    // int somme=0;
    // printf("la somme avant l'appel de la fonction: %d\n",somme);
    // summArray(t,sizeof(t),&somme);
    // printf("la somme aprés l'appel de la fonction :%d \n",somme);
    // free(t);
//----------------------------------------------------------------------------
//Q3
    //  test d'un tableau statique
    int t[5]={1,2,3,4,5};
   
    int empl;
    int *p=NULL;
    // printf("%d",searchArray(t,5,4,&p));
    // printf("la valeur de case %d \n",*p);
    fct_mi_max(t,5,&p);
    printf("%d",*p);



    //  test d'un tableau dynamique
    // int *t;
    // t=malloc(5*sizeof(int));
    // for (int i=0;i<=sizeof(t);i++){
    //         *(t+i)=i;
    // }
    // printf("%d",searchArray(t,11));
//----------------------------------------------------------------------------
//Q4

    // int tab[]={1,2,3,4}; 
    // int (* f)(int) = &fois_deux; 
    // int (* f1_var) (int,int)=&f1;
    // // appliquerATableauPurPointeurs(*f,tab,4); 
    // appliquerATableau(* f1_var,tab,4);
    // for (int i=0;i<4;i++){
    //     printf("%d ",tab[i]); 
    //     printf("\n");
    //  }

    // int ** tpf;
    // tpf=(int **)malloc(2*sizeof(int*));
    // for (int i=0;i<2;i++){
    //     *(tpf+i)=malloc(2*sizeof(int));
    // }

//----------------------------------------------------------------------------
//Q5
// int tab[]={1,2,3,4};
// int (* f)(int,int)=&inferieur;
// tri_proc(tab,4,*f);

// for(int i=0;i<4;i++){
//     printf("%d ",tab[i]);
// }
//  fuc_stack_overflow(0);


    return 0;
}