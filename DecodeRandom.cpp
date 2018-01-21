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
    std::vector<std::string> lMin0 = createListeStrings(0);
    std::vector<std::string> lMaj0 = createListeStrings(1);

    std::vector<std::string> lMin = createRandomDecal(lMin0);
    std::vector<std::string> lMaj = createRandomDecal(lMaj0);

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
    std::vector<std::string> lMin0 = createListeStrings(0);
    std::vector<std::string> lMaj0 = createListeStrings(1);

    std::vector<std::string> lMin = createRandomDecal(lMin0);
    std::vector<std::string> lMaj = createRandomDecal(lMaj0);

    std::string carac;

    for (unsigned int i = 0; i < phrase.size(); i++){
        carac = phrase[i];
        if(carac.compare(" ") != 0 && carac.compare("'") !=0){
            carac = charToRandomChar(carac, lMin, lMaj);}
        newPhrase += carac;
    }
    return newPhrase;
}

std::map<std::string, float> createDicoFreq(){
    std::map <std::string, float> dico;
    dico["e"] = 17.26f;
    dico["a"] = 8.40f;
    dico["s"] = 8.08f;
    dico["i"] = 7.34f;
    dico["n"] = 7.13f;
    dico["t"] = 7.07f;
    dico["r"] = 6.55f;
    dico["o"] = 5.26f;
    dico["l"] = 6.01f;
    dico["u"] = 5.74f;
    dico["d"] = 4.18f;
    dico["c"] = 3.03f;
    dico["m"] = 2.96f;
    dico["p"] = 3.01f;
    dico["g"] = 1.27f;
    dico["b"] = 1.06f;
    dico["v"] = 1.32f;
    dico["h"] = 0.92f;
    dico["f"] = 1.12f;
    dico["q"] = 0.99f;
    dico["y"] = 0.30f;
    dico["x"] = 0.45f;
    dico["j"] = 0.31f;
    dico["k"] = 0.05f;
    dico["w"] = 0.04f;
    dico["z"] = 0.12f;
    return dico;
}


std::map<float, std::string> createDicoReversed(){
    std::map <float, std::string> dico;
    dico[17.26f] = "e";
    dico[8.40f] = "a";
    dico[8.08f] = "s";
    dico[7.34f] = "i";
    dico[7.13f] = "n";
    dico[6.55f] = "r";
    dico[7.07f] = "t";
    dico[5.26f] = "o";
    dico[6.01f] = "l";
    dico[5.74f] = "u";
    dico[4.18f] = "d";
    dico[3.03f] = "c";
    dico[2.96f] = "m";
    dico[3.01f] = "p";
    dico[1.27f] = "g";
    dico[1.06f] = "b";
    dico[1.32f] = "v";
    dico[0.92f] = "h";
    dico[1.12f] = "f";
    dico[0.99f] = "q";
    dico[0.30f] = "y";
    dico[0.45f] = "x";
    dico[0.31f] = "j";
    dico[0.05f] = "k";
    dico[0.04f] = "w";
    dico[0.12f] = "z";
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
    std::string lettre;
    for(i = 0; i < phraseCodee.size(); i++){
        lettre = phraseCodee[i];
        dico[lettre] +=1;
    }
    return dico;
}

QString decodeRandom(QString phraseCodee, QString phraseClef, int mode){
    //Permet le codage/décodage à partir d'une phraseClef.
    //La fonction a deux modes, mode = 0 fait un codage, mode = 1 fait un decodage

    std::map<std::string, std::string> dico;
    std::vector<std::string> listeBasique = createListeStrings(0);
    QString phraseDecodee;

    dico[" "] = " "; dico["'"] = "'";

    for(int i = 0; i < 26; i++){ //On remplit le dico avec les correspondances. {a->e...}
        QString carac0 = "" + phraseClef[i];
        dico[carac0.toStdString()] = listeBasique[i];
    }

    if(mode == 1){

        std::map<std::string, std::string> dico_reversed;

        for (std::map<std::string, std::string>::iterator i = dico.begin(); i != dico.end(); i++)
            dico_reversed[i->second] = i->first;
        dico = dico_reversed;

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
    std::map<float, std::string> reversedDicoFrequences = createDicoReversed();
    std::map<std::string, int> dicoCount = countCaracs(phraseCodee);
    std::map<float, std::string>::iterator lower_bIterator; //Frequence juste en dessous de la valeur que l'on obtient par la suite
    std::map<float, std::string>::iterator upper_bIterator; //Frequence juste au dessus de la valeur que l'on obtient par la suite
    std::map<std::string, std::string> finalAssociations; //Dico final, du type "a" -> "e"... (a = crypte, e = obtenu)


    std::string carac;
    std::string phraseFinale = "";


    float freq;
    float upper_b;
    int freqSpace = dicoCount[" "];
    finalAssociations["'"] = "'";
    finalAssociations[" "] = " ";
    std::map<float, std::string>::iterator max;


    for(i = 0; i < phraseCodee.size(); i++){
        carac = phraseCodee[i];


        if(finalAssociations.count(carac) == 0){//si le caractère n'est pas encore dans la table.
            freq = (float) 100.0 * dicoCount[carac]/(phraseCodee.size() - freqSpace); //La frequence d'apparition de la première lettre donnée.

            upper_bIterator = reversedDicoFrequences.upper_bound(freq);
            upper_b = upper_bIterator -> first;
            max = std::max_element(reversedDicoFrequences.begin(), reversedDicoFrequences.end(), reversedDicoFrequences.value_comp());
            if(freq > max-> first) upper_b = max -> first;


            finalAssociations[carac] = reversedDicoFrequences[upper_b];
            reversedDicoFrequences.erase(upper_b);
        }
        phraseFinale += finalAssociations[carac];
    }
    return phraseFinale;
}
