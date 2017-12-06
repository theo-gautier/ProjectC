#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DecodeCesar.hpp"


int main()
{
    char m[50]; //Buffer de message d'entrée
    int index; //Reçoit l'entier envoyé

    /*char* s = "coucou je suis remi mouzayeke";
    char* message_code = decodeCesar(s, 2);
    printf("Message code : %s\n", message_code);*/

    printf("Entrez votre message codé : ");
    scanf("%s",m);
    /*printf("Entrez votre entier de décalage : ");
    scanf("%d",&index);*/

    //char* message_decode = decodeCesar(m,index);
    //printf("Avec un décalage de %d, le message est : %s\n",index,message_decode);

    char** l = liste_decodee(m);
    printListDecodee(l);

    return 0;
}

