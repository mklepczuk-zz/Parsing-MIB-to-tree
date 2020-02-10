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
	std::vector<datatypes *> sequence;
	datatypes(std::string name,std::string visibility,int id,std::string keyWord,std::string basicType,int minValue,unsigned long int size,std::vector<datatypes *> sequence)
		: name(name),visibility(visibility),id(id),keyWord(keyWord),basicType(basicType),minValue(minValue),size(size),sequence(sequence) {}
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