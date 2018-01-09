bool rechercher_mot(std::string Str, std::ifstream&  fich);
int scoreLigne(std::vector<std::string> vector_phrase, std::ifstream& fich);
std::vector<int> listScore(const std::vector<std::string> listPhrases);
const int maxInt(std::vector<int> scoreList);
const int maxPos(std::vector<int> scoreList);
const std::string bestDecode(std::string phrase);
