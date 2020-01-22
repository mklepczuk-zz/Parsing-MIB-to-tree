#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>

struct node{
	std::vector<node *> children;
	int mib;
	std::string name;
	//wskaünik na typ danych
};

class Tree
{
private:
	node *root;
	void Insert(std::vector<int>, std::string, node *);
	node *Search(std::string, node *);
	void Show(node *, int);

public:
	Tree();
	virtual ~Tree();

	void Insert(std::vector<int>, std::string);
	node *Search(std::string);
	void Show();
};

