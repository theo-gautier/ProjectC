#include "DecodeCesar.hpp"


int charToAscii(const char c){
    return static_cast<int>(c);
}

char asciiToChar(const int value){
    return static_cast<int>(value);
}

//inutile desormais on peut utiliser size


bool maj(const char c){
    //renvoie True si c'est une majuscule
    int value = charToAscii(c);
    return (value > 64 && value < 91); //Majuscule = appartient a [65,90], minuscule = appartient a [97,122]
}

char decaleCesar(const char c, const int index){
    /*A retenir : Entre 65 et 90 (compris), on a les majuscules. De 97 à 122, on a les minuscules.
     *  @param char d'entrée c, index de décalage index.
     *  @return la valeur en lettre décalée de la lettre
     */

    int ascii = charToAscii(c);

    if(maj(c)){ //Si le caractère est une majuscule.
        ascii + index > 90 ? ascii+= index - 26 : ascii += index; //Condition ternaire en C.
        //Si on depasse 90, on revient en arrière de 26 pour écrire la bonne lettre.

    }

    else if(charToAscii(c) == 32){ //Caractère espace.
        return c;
    }

    else{
        ascii + index > 122 ? ascii+= index - 26 : ascii += index;
    }
    return ascii;

}

std::string decodeCesar(const std::string message, const int index){
    std::string s = message;
    for(unsigned int i = 0; i < message.size() ; i++){
        s[i] = decaleCesar(message[i], index);
    }
    return s;
}

std::vector<std::string> listeDecodee(const std::string message){
    std::vector<std::string> l(26);
    for (int j = 0; j < 26; j++){
        l[j] = decodeCesar(message, j);
    }
    return l;
}

const std::vector<std::string> parsing(const std::string message){
//A partir d'un message, permet d'obtenir un vecteur qui comprend les mots du message
	std::string mot;
	std::vector<std::string> parsedList;

	for(unsigned int i = 0; i < message.size(); i++){
		if(message.compare(i,1," ")){ //Si la lettre n'est pas un espace...
			mot+=message[i];
			if(i == message.size() - 1){
				parsedList.push_back(mot);
				mot.clear();
			}
		}

		else{
			parsedList.push_back(mot);
			mot.clear();
		}
	}
	return parsedList;
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
