#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <streambuf>
#include "Types.h"
#include "Tree.h"

class ParserMIB
{
private:
	std::string LoadFile(std::string);
	void ParseImports(std::string, std::vector<datatypes *> *, Tree *);
	void ParseDataTypes(std::string, std::vector<datatypes *> *,std::string);
	void ParseIdentifiers(std::string,std::string,Tree *);
	void ParseObjects(std::string,std::vector<datatypes *> *,Tree *);

public:
	ParserMIB();
	virtual ~ParserMIB();
	void ParseMib(std::vector<datatypes *> *,Tree *);
};

