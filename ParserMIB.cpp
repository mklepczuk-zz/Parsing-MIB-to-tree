#include "stdafx.h"
#include "ParserMIB.h"

ParserMIB::ParserMIB()
{
}


ParserMIB::~ParserMIB()
{
}

void ParserMIB::ParseMib(std::vector<datatypes *> *listoftypes, Tree *tree)
{
	std::string loadedFile = LoadFile("../RFC1213-MIB.txt");
	ParseImports(loadedFile,listoftypes,tree);
	ParseDataTypes(loadedFile, listoftypes,"MIB");
	ParseIdentifiers(loadedFile,"MIB",tree);
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

void ParserMIB::ParseImports(std::string import,std::vector<datatypes *> *listoftypes, Tree *tree)
{
	std::regex re("IMPORTS\\s*.*\\n.*\\n\\s*FROM\\s(.*)");
	std::sregex_iterator next(import.begin(), import.end(), re);
	std::sregex_iterator end;
	std::smatch match = *next;
	std::string importedfile = LoadFile("../" + match.str(1) + ".txt");
	ParseDataTypes(importedfile, listoftypes,"import");
	ParseIdentifiers(importedfile,"import", tree);
}

void ParserMIB::ParseDataTypes(std::string import,std::vector<datatypes *> *listoftypes,std::string file)
{
	if(file == "import")
	{
		std::regex re("(\\w*)\\s*::=\\s*\\[([^ ]*)\\s*(\\d*)\\]\\s*\\n\\s*(\\w*)\\s*(\\w*\\s*\\w*)\\s*\\((\\d*)..(\\d*)");
		std::sregex_iterator next(import.begin(), import.end(), re);
		std::sregex_iterator end;
		while (next != end)
		{
			std::smatch match = *next;
			listoftypes->push_back(new datatypes(match.str(1),match.str(2),std::stoi(match.str(3)), match.str(4),match.str(5),std::stoi(match.str(6)),std::stoul(match.str(7))));
			next++;
		}

		std::regex re2("(\\w*)\\s*::=\\s*\\[([^ ]*)\\s*(\\d*)\\]\\s*--\\s*\\w*\\s*\\w*-\\w*\\s*\\w*\\n\\s*(\\w*)\\s*(\\w*\\s*\\w*)\\s*\\(SIZE\\s*\\((\\d*)");
		std::sregex_iterator next2(import.begin(), import.end(), re2);
		std::sregex_iterator end2;
		std::smatch match2 = *next2;
		listoftypes->push_back(new datatypes(match2.str(1),match2.str(2),std::stoi(match2.str(3)), match2.str(4),match2.str(5),0,std::stoi(match2.str(6))));

		std::regex re3("(\\w*)\\s*::=\\s*CHOICE\\s*\\{\\s*internet\\s*(\\w*)");
		std::sregex_iterator next3(import.begin(), import.end(), re3);
		std::sregex_iterator end3;
		std::smatch match3 = *next3;
		std::vector<datatypes *>::iterator iter = std::find_if(listoftypes->begin(), listoftypes->end(),[type = match3.str(2)](datatypes * obj)
			{ return obj->name == type;} );
		auto index = std::distance(listoftypes->begin(),iter);
		listoftypes->push_back(new datatypes(match3.str(1),listoftypes->at(index)->visibility,listoftypes->at(index)->id,listoftypes->at(index)->keyWord,
			listoftypes->at(index)->basicType,listoftypes->at(index)->minValue,listoftypes->at(index)->size));
	}

	if(file == "MIB")
	{
		std::regex re4("(\\w*)\\s*::=\\n\\s*(\\w*\\s*\\w*)\\n--");
		std::sregex_iterator next4(import.begin(), import.end(), re4);
		std::sregex_iterator end4;
		while (next4 != end4)
		{
			std::smatch match4 = *next4;
			listoftypes->push_back(new datatypes(match4.str(1),"",4,"",match4.str(2),0,255));
			next4++;
		}
	}
}

void ParserMIB::ParseIdentifiers(std::string import, std::string file, Tree *nTree)
{
	if(file == "import")
	{
		std::regex re("(\\w*)\\s*OBJECT IDENTIFIER ::= \\{ (\\w*) ((\\w*)\\((\\d*)\\) (\\w*)\\((\\d*)\\) )?(\\d*)");
		std::sregex_iterator next(import.begin(), import.end(), re);
		std::sregex_iterator end;
		while (next != end)
		{
			std::smatch match = *next;
			if(match[3].matched != false)
			{
				nTree->Insert(std::stoi(match.str(5)),match.str(2),match.str(4),nullptr);
				nTree->Insert(std::stoi(match.str(7)),match.str(4),match.str(6),nullptr);
				nTree->Insert(std::stoi(match.str(8)),match.str(6),match.str(1),nullptr);
			}
			else
			{
				nTree->Insert(std::stoi(match.str(8)),match.str(2),match.str(1),nullptr);
			}
			next++;
		}
	}
	if(file == "MIB")
	{
		std::regex re2("(\\w*)(\\-\\w*)?\\s*OBJECT IDENTIFIER ::= \\{ (\\w*)(\\-\\w*)?\\s*(\\d*)");
		std::sregex_iterator next2(import.begin(), import.end(), re2);
		std::sregex_iterator end2;
		while (next2 != end2)
		{
			std::smatch match2 = *next2;
			if(match2[4].matched == false)
			{
				nTree->Insert(std::stoi(match2.str(5)),match2.str(3),(match2.str(1)+match2.str(2)),nullptr);
			}
			else
			{
				nTree->Insert(std::stoi(match2.str(5)),(match2.str(3)+match2.str(4)),match2.str(1),nullptr);
			}
			next2++;
		}
	}
}
