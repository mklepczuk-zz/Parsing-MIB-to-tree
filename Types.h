#pragma once
#include <string>
#include <vector>

struct datatypes{
	std::string name;
	std::string visibility;
	int id;
	std::string keyWord;
	std::string basicType;
	int minValue;
	unsigned long int size;
	datatypes(std::string name,std::string visibility,int id,std::string keyWord,std::string basicType,int minValue,unsigned long int size)
		: name(name),visibility(visibility),id(id),keyWord(keyWord),basicType(basicType),minValue(minValue),size(size) {}
};

class Types
{
private:
	std::vector<datatypes *> *list;

public:
	Types();
	virtual ~Types();
	std::vector<datatypes *> *GetList();
};