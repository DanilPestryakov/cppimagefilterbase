#include "parser.h"

void parser::pars(char* filename)
{
	std::ifstream in(filename);
	std::string nameOfFilter;
	cParams str;
	while (in) {
		std::getline(in, nameOfFilter, ' ');
		if (nameOfFilter.find("Red") != -1) {
			str.nameOfFilter = "Red";
			in >> str.u;
			in >> str.l;
			in >> str.b;
			in >> str.r;
			filterQ.push_back(str);
		}
		if (nameOfFilter.find("Treshold") != -1) {
			str.nameOfFilter = "Treshold";
			in >> str.u;
			in >> str.l;
			in >> str.b;
			in >> str.r;
			filterQ.push_back(str);
		}
		
		if (nameOfFilter.find("Edge") != -1) {
			str.nameOfFilter = "Edge";
			in >> str.u;
			in >> str.l;
			in >> str.b;
			in >> str.r;
			filterQ.push_back(str);
		}
		if (nameOfFilter.find("Blur") != -1) {
			str.nameOfFilter = "Blur";
			in >> str.u;
			in >> str.l;
			in >> str.b;
			in >> str.r;
			filterQ.push_back(str);
		}
	}
}