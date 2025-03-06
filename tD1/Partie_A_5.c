#include <stdio.h>
#define pscanf(msg_dmd,format_rep,adress_donne){printf(%s,msg_dmd);scanf(format_rep,adress_donne);}
// #ifdef pscanf
//     printf("votre macro ça marche bien ");
// #endif
int main(int argc, char const *argv[]){
    pscanf("entre votre age","%d","&var");
    return 0;
}