#pragma once

#include "DecodeCesar.hpp"
#include "Donnees.hpp"
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <QString>

//Création de décalages/vecteurs
std::vector<std::string> createListeStrings(int maj);
std::vector<std::string> createRandomDecal(std::vector<std::string> listeStrings);
std::vector<std::string> createRandomDecal2(QString phraseClef);

//toRandom diverses
std::string charToRandom(std::string carac,
                         std::vector<std::string> decalageRandomMin,
                         std::vector<std::string> decalageRandomMaj);
std::string wordToRandomWord(std::string word);
std::string phraseToRandomPhrase(std::string phrase);

//Création de dictionnaires
std::map<std::string, float> createDicoFreq();
std::map<float, std::string> createDicoReversed();

//Passage en minuscule (utilisé pour le décodage).
std::string toMin(std::string carac);
std::string toMinPhrase(std::string phrase);

//Etude d'une phrase
std::map<std::string, int> countCaracs(std::string phraseCodee);

//Décodage final
QString decodeRandom(QString phraseCodee, QString phraseClef);
std::string bestDecodeRandom(std::string phraseCodee);
