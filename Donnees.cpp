#include "Donnees.hpp"


bool rechercher_mot(std::string Str){
    // recherche un mot dans le dictionnaire et renvoie true si celui-ci y est

    std::ifstream fichier("liste.de.mots.francais.frgut.txt");
    if (fichier){ //si le fichier a été bien chargé
        std::string ligne;
        while(getline(fichier,ligne)){ //tant qu'il reste des lignes => saut de ligne dans le fichier (curseur dans le fichier)
            if (Str == ligne){
                return true;
            }
        }
    }

    else{
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }

    return false;
}

int scoreLigne(std::vector<std::string> vector_phrase){
	//Obtient le score d'une ligne.
	unsigned int i;
	unsigned int score = 0;
    for(i = 0; i < vector_phrase.size(); i++){
        if(rechercher_mot(vector_phrase[i])){
            score++;}
        //fich.seekg(0, fich.beg); TODO : A implémenter
    }

    return score;
}


std::vector<int> listScore(const std::vector<std::string> listPhrases){
	//Utilise la liste decodee pour calculer le score de chaque ligne, et en fait une liste de score.
	//(Premier element = pas de decalage).

	std::vector<int> l; //Liste score
	unsigned int i;

	for (i = 0; i < listPhrases.size(); i++){
		l.push_back(scoreLigne(parsing(listPhrases[i])));}

	return l;
}

const int maxInt(std::vector<int> scoreList){
	std::vector<int>::iterator result;
	result = std::max_element(scoreList.begin(), scoreList.end());
	int pos = std::distance(scoreList.begin(),result);
	return scoreList[pos];
}

const int maxPos(std::vector<int> scoreList){
	std::vector<int>::iterator result;
	result = std::max_element(scoreList.begin(), scoreList.end());
	int pos = std::distance(scoreList.begin(),result);
	return pos;
}

const std::string bestDecode(std::string phrase){
	const std::vector<std::string> listPhrases = listeDecodee(phrase);
	int bestPos = maxPos(listScore(listPhrases));
	return listPhrases[bestPos];}

