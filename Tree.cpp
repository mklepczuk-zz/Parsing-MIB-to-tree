#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
}

void Tree::insert(std::vector<int> keys, std::string name)
{
	if(root != nullptr){
		keys.erase(keys.begin());
		insert(keys, name, root);
	}else{
		root = new node;
		root->mib = keys.front();
		root->name = name;
	}
}

node * Tree::search(std::string)
{
	return nullptr;
}

void Tree::insert(std::vector<int> keys, std::string name, node *leaf)
{
	if(keys.size() == 1){
		leaf->children.push_back(new node);
		leaf->children.back()->mib = keys.front();
		leaf->children.back()->name = name;
	}
}

node * Tree::search(std::string, node *)
{
	return nullptr;
}
