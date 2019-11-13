#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
}

void Tree::insert(int *keys, std::string name)
{
	if(root != nullptr){
		insert(keys, name, root, sizeof(keys));
	}else{
		root = new node;
		root->mib = keys[0];
		root->name = name;
	}
}

node * Tree::search(std::string)
{
	return nullptr;
}

void Tree::insert(int *keys, std::string name, node *leaf, int size)
{
	if(leaf->children.empty() == true){
		leaf->children.push_back(new node);
		leaf->children.back()->mib = keys[];
		leaf->children.back()->name = name;
	}
}

node * Tree::search(std::string, node *)
{
	return nullptr;
}
