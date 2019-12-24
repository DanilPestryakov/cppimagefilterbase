#include "parser.h"

void parser::pars(char* filename)
{
	std::ifstream in(filename);
	std::string nameOfFilter;
	cParams str;
	while (in) {
		std::getline(in, nameOfFilter, ' ');
		in >> str.u;
		in >> str.l;
		in >> str.b;
		in >> str.r;
		if (nameOfFilter.find("Red") != -1) {
			str.nameOfFilter = "Red";
			filterQ.push_back(str);
		}
		if (nameOfFilter.find("Treshold") != -1) {
			str.nameOfFilter = "Treshold";
			filterQ.push_back(str);
		}
		
		if (nameOfFilter.find("Edge") != -1) {
			str.nameOfFilter = "Edge";
			filterQ.push_back(str);
		}
		if (nameOfFilter.find("Blur") != -1) {
			str.nameOfFilter = "Blur";
			filterQ.push_back(str);
		}
	}
}


