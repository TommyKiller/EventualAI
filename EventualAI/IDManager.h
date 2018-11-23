#ifndef IDMANAGER_H
#define IDMANAGER_H


#include "CharacterID.h"
#include <functional>


namespace Identity
{
	class IDManager
	{
	private:
		static IDManager *_instance_;

		std::function<CharacterID *()> InitCharID(int seed);

		IDManager();

		IDManager(IDManager &) = delete;

		IDManager & operator=(IDManager &) = delete;

	public:
		static IDManager * GetInstance();

		static void Dispose();

		void Reset();

		std::function<CharacterID *()> GetCharID;

	};
}


#endif
