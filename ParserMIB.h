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
	void ParseImports(std::string, datatypes *);
	void ParseDataTypes(std::string, datatypes *);

public:
	ParserMIB();
	virtual ~ParserMIB();

	void ParseMib(datatypes *);
};

