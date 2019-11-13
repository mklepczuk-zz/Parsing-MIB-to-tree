#pragma once
#include <vector>
#include<string>

struct node{
	std::vector<node *> children;
	int mib;
	std::string name;
};

class Tree
{
private:
	node *root;
	void insert(int *, std::string, node *,int);
	node *search(std::string, node *);

public:
	Tree();
	virtual ~Tree();

	void insert(int *, std::string);
	node *search(std::string);
	//wyœwietlanie drzewa?
};

