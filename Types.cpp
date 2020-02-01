#include "stdafx.h"
#include "Types.h"

Types::Types()
{
	list = new std::vector<datatypes *>;
}

Types::~Types()
{
}

std::vector<datatypes *> *Types::GetList()
{
	return list;
}

/*std::vector<datatypes *>::iterator iter = std::find_if(listoftypes->begin(), listoftypes->end(),[type = name](datatypes * obj)
		{ return obj->name == type;} );

		if ( iter == listoftypes->end() )*/