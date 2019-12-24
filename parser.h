#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <istream>
#include <vector>
#include <fstream>
#include <iostream>


typedef struct cParams {
	std::string nameOfFilter;
	int u;
	int l;
	int b;
	int r;
}cParams;

class parser {
public:
	void pars(char* filename);
	int GetU(int i) { return this->filterQ[i].u; };
	int GetL(int i) { return this->filterQ[i].l; };
	int GetB(int i) { return this->filterQ[i].b; };
	int GetR(int i) { return this->filterQ[i].r; };
	std::string GetString(int i) { return this->filterQ[i].nameOfFilter; };
	int countOfFilters() { return this->filterQ.size(); };
private:
	std::vector<cParams> filterQ;
};
#endif // PARSER_H