
#include "Variant.h"

namespace Atlas
{

Variant::Variant()	{ rc=1; rt = None; }
Variant::~Variant()	{}

void	Variant::decref()
{
	if (--rc > 0) return;
	delete this;
}

list<VNum*>	VNum::freelist;
list<VStr*>	VStr::freelist;
list<VMap*>	VMap::freelist;
list<VVec*>	VVec::freelist;

}


