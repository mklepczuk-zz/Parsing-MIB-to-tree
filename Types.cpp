#include "stdafx.h"
#include "Types.h"

Types::Types()
{
	typesList = nullptr;
}

Types::~Types()
{
}

datatypes *Types::GetList()
{
	return typesList;
}
