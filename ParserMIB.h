#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <streambuf>

class ParserMIB
{
private:
	std::string importedFile;
	void LoadFile();

public:
	ParserMIB();
	virtual ~ParserMIB();

	void ParseMib() ;
	std::string GetFile();
};

