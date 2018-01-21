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

std::vector<std::string> createRandomDecal2(QString phraseClef){
    std::vector<std::string> listeStrings;
    int i;
    for(i = 0; i < phraseClef.size(); i++){
        QString carac = "" + phraseClef[i];
        listeStrings.push_back(carac.toStdString());
    }
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

std::map<std::string, float> createDicoFreq(){
    std::map <std::string, float> dico;
    dico["e"] = 12.10f;
    dico["a"] = 7.11f;
    dico["i"] = 6.59f;
    dico["s"] = 6.51f;
    dico["n"] = 6.39f;
    dico["r"] = 6.07f;
    dico["t"] = 5.92f;
    dico["o"] = 5.02f;
    dico["l"] = 4.96f;
    dico["u"] = 4.49f;
    dico["d"] = 3.67f;
    dico["c"] = 3.18f;
    dico["m"] = 2.62f;
    dico["p"] = 2.49f;
    dico["g"] = 1.23f;
    dico["b"] = 1.14f;
    dico["v"] = 1.11f;
    dico["h"] = 1.11f;
    dico["f"] = 1.11f;
    dico["q"] = 0.65f;
    dico["y"] = 0.46f;
    dico["x"] = 0.38f;
    dico["j"] = 0.34f;
    dico["k"] = 0.29f;
    dico["w"] = 0.17f;
    dico["z"] = 0.15f;
    return dico;
}


std::map<float, std::string> createDicoReversed(){
    std::map <float, std::string> dico;
    dico[12.14f] = "e";
    dico[7.11f] = "a";
    dico[6.59f] = "i";
    dico[6.51f] = "s";
    dico[6.39f] = "n";
    dico[6.07f] = "r";
    dico[5.92f] = "t";
    dico[5.02f] = "o";
    dico[4.96f] = "l";
    dico[4.49f] = "u";
    dico[3.67f] = "d";
    dico[3.18f] = "c";
    dico[2.62f] = "m";
    dico[2.49f] = "p";
    dico[1.23f] = "g";
    dico[1.14f] = "b";
    dico[1.11f] = "v";
    dico[1.11f] = "h";
    dico[1.11f] = "f";
    dico[0.65f] = "q";
    dico[0.46f] = "y";
    dico[0.38f] = "x";
    dico[0.34f] = "j";
    dico[0.29f] = "k";
    dico[0.17f] = "w";
    dico[0.15f] = "z";
    return dico;
}


std::string toMin(std::string carac){
    //Transforme un caractere en caractere minuscule
    int value;

    value = charToAscii(carac[0]);
    std::string result = "";
    return result + asciiToChar(value + 22);
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


std::map<std::string, int> countCaracs(std::string phraseCodee){
    /* Cette fonction permet, a partir d'une phrase codee (toute en minuscule),
       d'obtenir les frequences des lettres codees dans la phrase */
    unsigned int i;
    std::map<std::string, int> dico;
    std::string lettre = "";
    for(i = 0; i < phraseCodee.size(); i++){
        lettre[0]= phraseCodee[i];
        if(!lettre.compare(" ")){
            dico[lettre] ++;
        }
    }
    return dico;
}

QString decodeRandom(QString phraseCodee, QString phraseClef){
    //Permet le décodage à partir d'une phraseClef.
    std::vector<std::string> vecteurClef = createRandomDecal2(phraseClef);
    std::map<std::string, std::string> dico;
    std::vector<std::string> listeBasique = createListeStrings(0);
    QString phraseDecodee;

    for(int i = 0; i < 26; i++){ //On remplit le dico avec les correspondances. {a->e...}
        dico[listeBasique[i]] = vecteurClef[i];
    }

    for(int j = 0; j < phraseCodee.size(); j++){ //On créé la phrase décodée.
        QString carac1 = "" + phraseCodee[j];
        QString carac2 = QString::fromStdString(dico[carac1.toStdString()]);
        QString carac = "" + carac2;
        phraseDecodee += carac;
    }
    return phraseDecodee;
}


std::string bestDecodeRandom(std::string phraseCodee){
    //Décodage par BruteForce.

    unsigned int i;
    std::map<std::string, float> dicoFrequences = createDicoFreq();
    std::map<float, std::string> reversedDicoFrequences = createDicoReversed();
    std::map<std::string, int> dicoCount = countCaracs(phraseCodee);
    std::map<float, std::string>::iterator lower_bIterator; //Frequence juste en dessous de la valeur que l'on obtient par la suite
    std::map<float, std::string>::iterator upper_bIterator; //Frequence juste au dessus de la valeur que l'on obtient par la suite
    std::map<std::string, std::string> finalAssociations; //Dico final, du type "a" -> "e"... (a = crypte, e = obtenu)


    std::string carac;
    std::string phraseFinale = phraseCodee;
    float freq;
    float lower_b; float upper_b;
    float dist1; float dist2;

    for(i = 0; i < phraseCodee.size(); i++){
        carac = phraseCodee[i];
        freq = dicoCount[phraseCodee]/phraseCodee.size(); //La frequence d'apparition de la première lettre donnée.
        lower_bIterator = reversedDicoFrequences.lower_bound(freq);
        upper_bIterator = reversedDicoFrequences.upper_bound(freq);
        lower_b = lower_bIterator -> first;
        upper_b = upper_bIterator -> first;

        dist1 = freq - lower_b;
        dist2 = upper_b - freq;
        if(dist1 < dist2){ //Si la frequence associee la plus proche est celle de lower_b, on remplace la lettre par celle donnee grace à lower_b.
            finalAssociations[carac] = reversedDicoFrequences[lower_b];
        }
        else{
            finalAssociations[carac] = reversedDicoFrequences[upper_b];
        }
        phraseFinale+=finalAssociations[carac][0];

    }

    return phraseFinale;
}
