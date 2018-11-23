#include "IDManager.h"


using namespace Identity;
IDManager * IDManager::_instance_ = nullptr;

IDManager::IDManager()
{
	Reset();
}

std::function<CharacterID *()> IDManager::InitCharID(int seed)
{
	return [=]() mutable { return new CharacterID(seed++); };
}

IDManager * IDManager::GetInstance()
{
	if (!_instance_)
	{
		_instance_ = new IDManager();
	}

	return _instance_;
}

void IDManager::Dispose()
{
	delete _instance_;
}

void IDManager::Reset()
{
	GetCharID = InitCharID(0);
}
