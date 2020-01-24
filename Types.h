#pragma once
#include <string>

struct datatypes{
	std::string name;
	std::string visibility;
	int id;
	std::string keyWord;
	std::string basicType;
	int size;
	int minValue;
	int maxValue;
};

class Types
{
private:
	datatypes *typesList;

public:
	Types();
	virtual ~Types();
	datatypes *GetList();
};