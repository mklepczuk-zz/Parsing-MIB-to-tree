#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Types.h"

struct node{
	std::vector<node *> children;
	int mib;
	std::string name;
	datatypes *type;
	std::string access;
	std::string status;
	std::string description;
	node(std::vector<node *> children,int mib,std::string name,datatypes *type, std::string access, std::string status, std::string description)
		: children(children), mib(mib), name(name), type(type), access(access), status(status), description(description) {}
};

class Tree
{
private:
	node *root, *found;
	void Insert(int, std::string, std::string, std::string, std::string, std::string, datatypes *,node *);
	void SearchName(std::string, node *);
	void Show(node *);

public:
	Tree();
	virtual ~Tree();

	void Insert(int, std::string, std::string, std::string, std::string, std::string, datatypes *);
	void SearchName(std::string);
	void Show();
	node *GetFound();
};

