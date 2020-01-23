#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <streambuf>

class ParserMIB
{
private:
	std::string LoadFile(std::string);
	void ParseImports(std::string);

public:
	ParserMIB();
	virtual ~ParserMIB();

	void ParseMib();
};

