/*
    Documentation section
    @Project partie1_td1
    @Author Oubakki Ayoub
    @Created 07/02/2025
    @Program Description, Program to compute the area of a cirlce
*/

#include <stdio.h>
#include <stdarg.h>
//Q1
int sum(int a, int b, ...) {
    int var_sum = a + b;
    va_list args;//Declarer une liste des arguments 
    va_start(args, b);//Initialise la liste à partir du dernier paramètre connu b
    int vl;
    while ((vl = va_arg(args, int)) != 0) { 
        var_sum += vl;
    }
    va_end(args);
    return var_sum;
}

// fonction main
int main(int argc, char const *argv[]){
    printf("la somme est %d",sum(4,16,20,0));
    return 0;
}