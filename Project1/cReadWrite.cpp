#include "cReadWrite.h"


std::vector<std::string> cReadWrite::getSoundFromFile(std::string fileName) {

	std::vector<std::string> result;
	std::stringstream ss;
	ss << SOLUTION_DIR << "common\\assets\\audio\\" << fileName;

	//read file 
	std::ifstream inputFile(ss.str());
	std::string line;
	while (std::getline(inputFile, line)) {
		result.push_back(line);
	}

	return result;
}