#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "DecodeCesar.hpp"

int charToAscii(char c){
    return (int)c;
}

char asciiToChar(int value){
    return (char)value;
}

int mylen(char* message){
    int c = 0;
    while(*message++ != '\0'){
        c++;
    }
    return c;
}

bool maj(char c){
    int value = charToAscii(c);
    if(value > 64 && value < 91){
        return true;
    }
    else{
        return false;
    }

}


char decaleCesar(char c, int index){
    /*A retenir : Entre 65 et 90 (compris), on a les majuscules. De 97 à 122, on a les minuscules.
     *  @param char d'entrée c, index de décalage index.
     *  @return la valeur en lettre décalée de la lettre
     */

    int ascii = charToAscii(c);

    if(maj(c)){ //Si le caractère est une majuscule.
        ascii + index > 90 ? ascii+= index - 26 : ascii += index; //Condition ternaire en C.
        //Si on dépasse 90, on revient en arrière de 26 pour écrire la bonne lettre.

    }

    else if(charToAscii(c) == 32){ //Caractère espace.
        return c;
    }

    else{
        ascii + index > 122 ? ascii+= index - 26 : ascii += index;
    }
    return ascii;

}

char* decodeCesar(char* message, int index){
    char* s = (char*) malloc(100); //Obligation de mettre un cast.

    for(int i = 0; i < mylen(message); i++){
        *(s+i) = decaleCesar(*(message+i), index);
    }

    *(s+mylen(message)) = '\0';
    return s;
}

char** liste_decodee(char* message){
    char** l = (char**) malloc(100);
    for (int j = 0; j < 26; j++){
        *(l+j) = decodeCesar(message, j);
    }
    return l;
}

void printListDecodee(char** l){
    printf("(");
    for (int j = 0; j < 26; j++){
        printf("%s, ", *(l+j));
    }
    printf(")");

}
