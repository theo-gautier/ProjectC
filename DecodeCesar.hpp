#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>



std::string decodeCesar(const std::string str_in);
int charToAscii(const char c);
char decaleCesar(const char c, const int index);
bool maj(const char c);
char asciiToChar(const int value);
std::string decodeCesar(const std::string str_in, const int index);
std::vector<std::string> listeDecodee(const std::string message);
const std::vector<std::string> parsing(const std::string message);
void printVectorString(const std::vector<std::string> l);
void printVectorInt(const std::vector<int> l);
