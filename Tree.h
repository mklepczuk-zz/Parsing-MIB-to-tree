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
	void insert(std::vector<int>, std::string, node *);
	node *search(std::string, node *);
	void show(node *, int);

public:
	Tree();
	virtual ~Tree();

	void insert(std::vector<int>, std::string);
	node *search(std::string);
	void show();
};

