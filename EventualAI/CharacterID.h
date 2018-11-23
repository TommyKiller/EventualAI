#ifndef CHARACTERID_H
#define CHARACTERID_H


#include "ID.h"


namespace Identity
{
	class CharacterID :
		public ID
	{
	public:
		CharacterID(int id);

		CharacterID(CharacterID &);
	};
}

#endif
