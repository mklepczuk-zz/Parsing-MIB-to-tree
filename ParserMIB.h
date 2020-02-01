#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <streambuf>
#include "Types.h"

class ParserMIB
{
private:
	std::string LoadFile(std::string);
	void ParseImports(std::string, std::vector<datatypes *> *);
	void ParseDataTypes(std::string, std::vector<datatypes *> *,std::string);

public:
	ParserMIB();
	virtual ~ParserMIB();

	void ParseMib(std::vector<datatypes *> *);
};

