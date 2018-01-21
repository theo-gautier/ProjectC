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


std::vector<std::string> createListeStrings(int maj);
std::vector<std::string> createRandomDecal(std::vector<std::string> listeStrings);
std::string charToRandom(std::string carac,
                         std::vector<std::string> decalageRandomMin,
                         std::vector<std::string> decalageRandomMaj);
std::string wordToRandomWord(std::string word);
std::string phraseToRandomPhrase(std::string phrase);
std::map<std::string, float> createDico();

