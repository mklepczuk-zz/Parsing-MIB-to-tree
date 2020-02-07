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
	node(std::vector<node *> children,int mib,std::string name,datatypes *type) : children(children), mib(mib), name(name), type(type){}
};

class Tree
{
private:
	node *root, *found;
	void Insert(int, std::string, std::string, datatypes *,node *);
	void SearchName(std::string, node *);
	void Show(node *);

public:
	Tree();
	virtual ~Tree();

	void Insert(int, std::string, std::string, datatypes *);
	void SearchName(std::string);
	void Show();
	node *GetFound();
};

