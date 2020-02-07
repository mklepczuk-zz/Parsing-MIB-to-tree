#include "stdafx.h"
#include "Tree.h"

Tree::Tree()
{
	root = new node(std::vector<node *>(),1,"iso",nullptr);
}

Tree::~Tree()
{
}

void Tree::Insert(int key, std::string parent_name, std::string child_name, datatypes *type)
{
	//keys.erase(keys.begin());
	Insert(key, parent_name, child_name, type, root);
}

void Tree::Show()
{
	Show(root);
}

node *Tree::GetFound()
{
	return found;
}

void Tree::SearchName(std::string name)
{
	return SearchName(name,root);
}

void Tree::Insert(int key, std::string parent_name, std::string child_name, datatypes *type, node *leaf)
{
	std::vector<node *>::iterator iter = std::find_if(leaf->children.begin(), leaf->children.end(),[&mib = parent_name](node * obj)
	{ return obj->name == mib;} );

	if ( iter != leaf->children.end() )
	{
		auto index = std::distance(leaf->children.begin(),iter);
		leaf->children.at(index)->children.push_back(new node(std::vector<node *>(),key,child_name,type));
		return;
	} 
	else if (leaf->children.size() > 0)
	{
		for (size_t index = 0; index < leaf->children.size(); index++)
		{
			Insert(key, parent_name, child_name, type, leaf->children.at(index));
		}
	}
	else if (leaf->name == parent_name)
	{
		leaf->children.push_back(new node(std::vector<node *>(),key,child_name,type));
	}
}

void Tree::Show(node * leaf)
{
	std::cout<<leaf->mib<<" "<<leaf->name<<"\n";
	if (leaf->children.size() > 0)
	{
		std::cout<<"\n";
		for(std::vector<node *>::iterator it = leaf->children.begin() ; it != leaf->children.end(); it++)
		{
			auto index = std::distance(leaf->children.begin(),it);
			Show(leaf->children.at(index));
		}
	}
	else
	{
		return;
	}
}

void Tree::SearchName(std::string name, node * leaf)
{
	std::vector<node *>::iterator iter = std::find_if(leaf->children.begin(), leaf->children.end(),[&mib = name](node * obj)
	{ return obj->name == mib;} );

	if ( iter != leaf->children.end() )
	{
		auto index = std::distance(leaf->children.begin(),iter);
		found = leaf->children.at(index);
	} 
	else if (leaf->children.size() > 0)
	{
		for (size_t index = 0; index < leaf->children.size(); index++)
		{
			SearchName(name, leaf->children.at(index));
		}
	}
}

//                   INSERT BY OID (1.3.6.3.2)
/*std::vector<node *>::iterator iter = std::find_if(leaf->children.begin(), leaf->children.end(),[&mib = keys](node * obj)
	{ return obj->mib == mib.front();} );

	if ( iter != leaf->children.end() )
	{
		auto index = std::distance(leaf->children.begin(),iter);
		keys.erase(keys.begin());
		Insert(keys, name, leaf->children.at(index));

	} else 
	{
		leaf->children.push_back(new node);
		leaf->children.back()->mib = keys.front();
		leaf->children.back()->name = name;
	}

//					INSERT DO DRZEWA poprzednia wersja
	if ( iter != leaf->children.end() )
	{
		auto index = std::distance(leaf->children.begin(),iter);
		Insert(key, parent_name, child_name, type, leaf->children.at(index));
	} 
	else if (leaf->children.size() > 0 && leaf->name != parent_name)
	{
		for (size_t index = 0; index < leaf->children.size(); index++)
		{
			Insert(key, parent_name, child_name, type, leaf->children.at(index));
		}
	}
	else if (leaf->name == parent_name)
	{
		leaf->children.push_back(new node(std::vector<node *>(),key,child_name,type));
	}*/
