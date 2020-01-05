#include "stdafx.h"
#include "Tree.h"
#define COUNT 5

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

void Tree::show()
{
	show(root,0);
}

node * Tree::search(std::string)
{
	return nullptr;
}

void Tree::insert(std::vector<int> keys, std::string name, node *leaf)
{
	std::vector<node *>::iterator iter = std::find_if(leaf->children.begin(), leaf->children.end(),[&mib = keys](node * obj){
		return obj->mib == mib.front(); } );

	if ( iter != leaf->children.end() ){

		int index = std::distance(leaf->children.begin(),iter);
		keys.erase(keys.begin());
		insert(keys, name, leaf->children.at(index));

	} else {

		leaf->children.push_back(new node);
		leaf->children.back()->mib = keys.front();
		leaf->children.back()->name = name;
	}
}

void Tree::show(node * leaf, int space)
{
	if (leaf->children.front() == nullptr)  
        return;

	// Increase distance between levels
    space += COUNT;
  
    // Print current node after space
	for (std::vector<node *>::iterator it = leaf->children.begin() ; it != leaf->children.end(); it++)
	{
		std::cout<<std::endl;
		for (int i = COUNT; i < space; i++)
			std::cout<<" ";
		std::cout<<(*it)->mib<<(*it)->name<<"\n";
	}
    return;
}

node * Tree::search(std::string, node *)
{
	return nullptr;
}
