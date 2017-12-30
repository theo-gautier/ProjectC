#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "DecodeCesar.hpp"
#include <stdlib.h>

int charToAscii(const char c){
    return static_cast<int>(c);
}

char asciiToChar(const int value){
    return static_cast<int>(value);
}

//inutile d�sormais on peut utiliser size


bool maj(const char c){
    //renvoie True si c'est une majuscule
    int value = charToAscii(c);
    return (value > 64 && value < 91);
}

char decaleCesar(const char c, const int index){
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

std::string decodeCesar(const std::string message, const int index){
    std::string s = message;
    for(int i = 0; i < message.size() ; i++){
        s[i] = decaleCesar(message[i], index);
    }
    return s;
}

std::vector<std::string> liste_decodee(const std::string message){
    std::vector<std::string> l(26);
    for (int j = 0; j < 26; j++){
        l[j] = decodeCesar(message, j);
    }
    return l;
}

void printVectorString(const std::vector<std::string> l){ 
    std::cout << "(" << std::endl;
    for (int j = 0; j < 26; j++){
        std::cout << l[j] << std::endl;
    }
    std::cout << ")" << std::endl;
}

void printVectorInt(const std::vector<int> l){
    std::cout << "(" << std::endl;
    for (int j = 0; j < 26; j++){
        std::cout << l[j] << std::endl;
    }
    std::cout << ")" << std::endl;
}
