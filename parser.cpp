#include "parser.h"

void parser::pars(char* filename)
{
	std::ifstream in(filename);
	std::string nameOfFilter;
	while (std::getline(in, nameOfFilter)) {
		if ((int)nameOfFilter.find("Red") != -1) {
			str.nameOfFilter = "Red";
			nameOfFilter.erase(0, 4);
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}
		if ((int)nameOfFilter.find("Treshold") != -1) {
			str.nameOfFilter = "Treshold";
			nameOfFilter.erase(0, 9);
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}

		if ((int)nameOfFilter.find("Edge") != -1) {
			str.nameOfFilter = "Edge";
			nameOfFilter.erase(0, 5);
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}
		if ((int)nameOfFilter.find("Blur") != -1) {
			str.nameOfFilter = "Blur";
			nameOfFilter.erase(0, 5);
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}
	}
}


void parser::parsStr(std::string Str) {
	int pos = Str.find(" ");
	std::string subStr(Str.substr(0, pos));
	str.u = stoi(subStr);
	Str.erase(0, pos + 1);
	pos = Str.find(" ");
	subStr = Str.substr(0, pos);
	str.l = stoi(subStr);
	Str.erase(0, pos + 1);
	pos = Str.find(" ");
	subStr = Str.substr(0, pos);
	str.b = stoi(subStr);
	Str.erase(0, pos + 1);
	subStr = Str.substr(0, Str.length());
	str.r = stoi(subStr);
}
