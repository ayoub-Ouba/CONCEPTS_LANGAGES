/*
    Documentation section
    @Project Geometrie en L3 
    @Author Marie-Laure Nivet
    @Created 20221010
    @Program Description, Program to compute the area of a cirlce
*/

//Link section
#include <stdio.h>



//Function prototype declaration section
int recursivite_clasique(int n){
    if(n==0) return 1;
    return n*recursivite_clasique(n-1);
} 
int recursivite_terminal(int n,int accum){
    if(n==0) return accum;
    
    return recursivite_terminal(n-1,n * accum);
}
int recursivite_clasique2(int n,int puis){
    if(puis==1) return n;
    return n*recursivite_clasique2(n,puis-1);
}    
int recursivite_terminal2(int n,int puis,int accum){
    if(puis==1) return accum;
    return recursivite_terminal2(n,puis-1,(puis-1)*n*accum);
}  

//Main function
int main(int argc, char const *argv[])
{
    printf("%d \n",recursivite_clasique(5));
    printf("%d \n",recursivite_terminal(5,1));
    printf("%d \n",recursivite_clasique2(2,3));
    printf("%d \n",recursivite_terminal2(2,3,1));
 
    return 0;
}



