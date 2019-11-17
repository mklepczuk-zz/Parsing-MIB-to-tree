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
	std::vector<node *>::iterator iter = std::find_if(leaf->children.begin(), leaf->children.end(),[&mib = keys](node * const& obj){
		return obj->mib == mib.front(); } );

	if ( iter != leaf->children.end() ){

		int index = std::distance(leaf->children.begin(),iter);
		keys.erase(keys.begin());
		insert(keys, name, leaf->children.at(index));

	} else {

		if(keys.size() == 1){
			leaf->children.push_back(new node);
			leaf->children.back()->mib = keys.front();
			leaf->children.back()->name = name;
		}
	}
}

node * Tree::search(std::string, node *)
{
	return nullptr;
}
