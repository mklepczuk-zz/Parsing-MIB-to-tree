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
	LoadFile();
}

std::string ParserMIB::GetFile()
{
	return ParserMIB::importedFile;
}

void ParserMIB::LoadFile()
{
	std::ifstream in("../RFC1213-MIB.txt", std::ios::in | std::ios::binary);
	if (in)
	{
		ParserMIB::importedFile = std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	}
	else
	{
		ParserMIB::importedFile = std::string(NULL);
	}

}
