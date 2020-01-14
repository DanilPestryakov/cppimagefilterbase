#include "parser.h"

void parser::pars(char* filename)
{
	std::ifstream in(filename);
	std::string line;
	int counter = 0;
	while (getline(in, line)) {
		cParams Str;
		std::istringstream i(line);
		for (std::string str; i >> str;) {
			if (counter == 0)
				Str.nameOfFilter = str;
			if (counter == 1)
				Str.u = (stoi(str));
			if (counter == 2)
				Str.l = (stoi(str));
			if (counter == 3)
				Str.b = (stoi(str));
			if (counter == 4)
				Str.r = (stoi(str));
			counter++;
		}
		filterQ.push_back(Str);
		counter = 0;
	}
}
