#include "DecodeRandom.hpp"


/* Preliminaire requis pour decalages :
 * Majuscule = appartient a [65,90], minuscule = appartient a [97,122]
 */

std::vector<std::string> createListeStrings(int maj){
    /*Si le parametre est 1, renvoie une liste de majuscules.
      Sinon, une liste de minuscules.
      La liste est du type : {"a","b","c","d",...}*/

    std::vector<std::string> listeStrings;
    std::string s;
    if(maj == 1) s = 'A';
    else s = 'a';

    for (int i = 0; i < 26; i++){
        listeStrings.push_back(s);
        s[0]++;
    }
    return listeStrings;
}

std::vector<std::string> createRandomDecal(std::vector<std::string> listeStrings){
    //Fonction qui sert a obtenir une liste decalee de facon random (du type {"c","z","h","i","b","m","p"...})
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(listeStrings.begin(), listeStrings.end()); //Liste shufflee.
    return listeStrings;
}

std::string charToRandomChar(std::string carac,
                         std::vector<std::string> decalageRandomMin,
                         std::vector<std::string> decalageRandomMaj){
    /*Cette fonction permet, a partir d'un caractere de type string,
     d'obtenir le caractere decale.*/

    int index;
    if(maj(carac[0])){ //Si on a une majuscule.
        index = charToAscii(carac[0]) - 65;
        return decalageRandomMaj[index];
    }
    else{
        index = charToAscii(carac[0]) - 97;
        return decalageRandomMin[index];
    }
}

std::string wordToRandomWord(std::string word){
    //Transforme un mot en un mot random.

    std::string newWord;
    std::vector<std::string> lMin = createListeStrings(0);
    std::vector<std::string> lMaj = createListeStrings(1);

    std::string carac;
    std::string carac2;
    for (unsigned int i = 0; i < word.size(); i++){
        carac2 = word[i];
        carac = charToRandomChar(carac2, lMin, lMaj);
        newWord += carac;
    }

    return newWord;
}

std::string phraseToRandomPhrase(std::string phrase){
    std::string newPhrase;
    std::vector<std::string> lMin = createListeStrings(0);
    std::vector<std::string> lMaj = createListeStrings(1);

    std::string carac;
    std::string carac2;

    for (unsigned int i = 0; i < phrase.size(); i++){
        if(!(phrase.compare(i,1," ") || phrase.compare(i,1,"'"))){ //message.compare(i,1," ")
            carac2 = phrase[i];
            carac = charToRandomChar(carac2, lMin, lMaj);
            newPhrase += carac;}
        else{
            newPhrase+=phrase[i];
        }
    }
    return newPhrase;
}

std::map createDico(){
    std::map <std::string, float> dico;
    dico["e"] = 12,10;
    dico["a"] = 7,11;
    dico["i"] = 6,59;
    dico["s"] = 6,51;
    dico["n"] = 6,39;
    dico["r"] = 6,07;
    dico["t"] = 5,92;
    dico["o"] = 5,02;
    dico["l"] = 4,96;
    dico["u"] = 4,49;
    dico["d"] = 3,67;
    dico["c"] = 3,18;
    dico["m"] = 2,62;
    dico["p"] = 2,49;
    dico["g"] = 1,23;
    dico["b"] = 1,14;
    dico["v"] = 1,11;
    dico["h"] = 1,11;
    dico["f"] = 1,11;
    dico["q"] = 0,65;
    dico["y"] = 0,46;
    dico["x"] = 0,38;
    dico["j"] = 0,34;
    dico["k"] = 0,29;
    dico["w"] = 0,17;
    dico["z"] = 0,15;
}


std::string toMin(std::string carac){
    //Transforme un caractere en caractere minuscule
    int value;

    value = charToAscii(carac);
    return asciiToChar(value + 22);
}

std::string toMinPhrase(std::string phrase){
    //Transforme une phrase en phrase en minuscule.
    std::string phraseMin;
    std::string carac;
    std::string carac2;

    for(unsigned int i = 0; i < phrase.size(); i++){
        if(!(phrase.compare(i,1," ") || phrase.compare(i,1,"'"))){ //message.compare(i,1," ")
            carac2 = phrase[i];
            carac = toMin(carac2);
            phraseMin += carac;
        }else{
            phraseMin += phrase[i];
        }
    }
    return phraseMin;
}


std::vector<int> countCaracs(std::string phraseCodee){
    /* Cette fonction permet, a partir d'une phrase codee (toute en minuscule),
       d'obtenir les frequences des lettres codees dans la phrase */




}

std::string bestDecodeRandom(){
    return " ";
}
