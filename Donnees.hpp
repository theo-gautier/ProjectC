#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include "DecodeCesar.hpp"


bool rechercher_mot(std::string Str);
int scoreLigne(std::vector<std::string> vector_phrase);
std::vector<int> listScore(const std::vector<std::string> listPhrases);
const int maxInt(std::vector<int> scoreList);
const int maxPos(std::vector<int> scoreList);
const std::string bestDecode(std::string phrase);
