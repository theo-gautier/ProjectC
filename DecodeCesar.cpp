#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "DecodeCesar.hpp"
#include <stdlib.h>

int charToAscii( char c){
    return (int)c;
}

char asciiToChar( int value){
    return (char)value;
}

//inutile d�sormais on peut utiliser size


bool maj( char c){
    //renvoie True si c'est une majuscule
    int value = charToAscii(c);
    return (value > 64 && value < 91);
}

char decaleCesar(char c,  int index){
    /*A retenir : Entre 65 et 90 (compris), on a les majuscules. De 97 � 122, on a les minuscules.
     *  @param char d'entr�e c, index de d�calage index.
     *  @return la valeur en lettre d�cal�e de la lettre
     */
    
    //Ajout d'un commentaire DE TESTTTT
    int ascii = charToAscii(c);
    
    if(maj(c)){ //Si le caract�re est une majuscule.
        ascii + index > 90 ? ascii+= index - 26 : ascii += index; //Condition ternaire en C.
        //Si on d�passe 90, on revient en arri�re de 26 pour �crire la bonne lettre.
        
    }
    
    else if(charToAscii(c) == 32){ //Caract�re espace.
        return c;
    }
    
    else{
        ascii + index > 122 ? ascii+= index - 26 : ascii += index;
    }
    return ascii;
    
}

std::string decodeCesar(std::string message, int index){
    std::string s = message;
    for(int i = 0; i < message.size() ; i++){
        s[i] = decaleCesar(message[i], index);
    }
    return s;
}

std::vector<std::string> liste_decodee(std::string message){
    std::vector<std::string> l(26);
    for (int j = 0; j < 26; j++){
        l[j] = decodeCesar(message, j);
    }
    return l;
}

void printListDecodee(std::vector<std::string> l){
    std::cout << "(" << std::endl;
    for (int j = 0; j < 26; j++){
        std::cout << l[j] << std::endl;
    }
    std::cout << ")" << std::endl;
}
