#include "stdafx.h"
#include "ParserMIB.h"

ParserMIB::ParserMIB()
{
}


ParserMIB::~ParserMIB()
{
}

void ParserMIB::ParseMib()
{
	std::string loadedFile = LoadFile("../RFC1213-MIB.txt");
	ParseImports(loadedFile);
}

std::string ParserMIB::LoadFile(std::string path)
{
	std::string temp;
	std::ifstream in(path, std::ios::in | std::ios::binary);
	if (in)
	{
		temp = std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	}
	else
	{
		temp = std::string(NULL);
	}
	return temp;
}

void ParserMIB::ParseImports(std::string import)
{
	std::regex re("IMPORTS\\s*(.*)\\s*FROM\\s*(.*)");
	std::sregex_iterator next(import.begin(), import.end(), re);
	std::sregex_iterator end;
	while (next != end)
	{
		std::smatch match = *next;
		next++;
		if(match.str(2).size() > 0)
		{
			std::string importedfile = LoadFile("../" + match.str(2) + ".txt");
			// parse datatype
			// parse OID
		}
	}
}
