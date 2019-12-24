#include "parser.h"

void parser::pars(char* filename)
{
	std::ifstream in(filename);
	std::string nameOfFilter;
	while (std::getline(in, nameOfFilter)) {
		if (nameOfFilter.find("Red") != -1) {
			str.nameOfFilter = "Red";
			nameOfFilter.erase(0, 4);
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}
		if (nameOfFilter.find("Treshold") != -1) {
			str.nameOfFilter = "Treshold";
			nameOfFilter.erase(0, 9);
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}
		
		if (nameOfFilter.find("Edge") != -1) {
			str.nameOfFilter = "Edge";
			nameOfFilter.erase(0, 5);	
			parsStr(nameOfFilter);
			filterQ.push_back(str);
		}
		if (nameOfFilter.find("Blur") != -1) {
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
	//std::cout << "(" << subStr.length() << ")" << std::endl;

	str.u = MyStoi((std::string)subStr);
	//std::cout << "(" << str.u << ")" << std::endl;

	Str.erase(0, pos + 1);
	pos = Str.find(" ");
	subStr = Str.substr(0, pos);
	//std::cout << "(" << subStr << ")" << std::endl;
	str.l = MyStoi((std::string)subStr);
	//std::cout << "(" << str.l << ")" << std::endl;

	Str.erase(0, pos + 1);
	pos = Str.find(" ");
	subStr = Str.substr(0, pos);
	//std::cout << "(" << subStr << ")" << std::endl;
	str.b = MyStoi((std::string)subStr);
	//std::cout << "(" << str.b << ")" << std::endl;

	Str.erase(0, pos + 1);
	subStr = Str.substr(0, Str.length());
	//std::cout << "(" << Str << ")" << std::endl;
	str.r = MyStoi((std::string)subStr);
//	std::cout << "(" << str.r << ")" << std::endl;

}

int parser::MyStoi(std::string str)
{
	int sum = 0;
	for (int i = 0; i < (int)str.length(); i++)
		sum = sum * 10 + (int)str[i] - 48;
	return sum;
}