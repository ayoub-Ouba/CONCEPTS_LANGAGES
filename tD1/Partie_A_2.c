#include <stdio.h>

//permet d'inclure la definition de boolean 
#include <stdbool.h>

float moyenne_func(int Nlv,int Nf,int Nm,int Np){
    return Nlv+Nf+Nm+Np/4;
}

bool verifier(int Nlv,int Nf,int Nm,int Np){
    float moyenne=moyenne_func(Nlv,Nf,Nm,Np);
    if(moyenne>10){
        return true ;
    }else if(Nm>(moyenne && Nf>(moyenne))){
        return true;
    }else if(Nlv && Nf>10 && Nm>10 && Np>10){
        return true;
    }else if(Nlv<10 || Nf<10 || Nm<10 || Np<10){
        return true;
    }else if(Nlv+Nf/2==10 || Nm+Np/2==10){
        return true;
    }else if(moyenne>=10 && (Nlv+Nf/2==10 || Nm+Np/2==10) ){
        return true;
    }else{
        return false;
    }
}


int main(int argc, char const *argv[]){
    return 0;
}