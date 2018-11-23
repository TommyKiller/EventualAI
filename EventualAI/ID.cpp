#include "ID.h"


using namespace Identity;


ID::ID(std::string id)
	: _id_(id)
{
}

ID::ID(ID & id)
{
	_id_ = id._id_;
}

bool ID::operator==(const ID & id) const
{
	return (_id_ == id._id_) ? true : false;
}

std::ostream & Identity::operator<<(std::ostream & os, const ID & id)
{
	os << id._id_;
	return os;
}

ID::~ID()
{
}
