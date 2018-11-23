#include "CharacterID.h"


Identity::CharacterID::CharacterID(int id)
	: ID("CH" + std::to_string(id))
{
}

Identity::CharacterID::CharacterID(CharacterID & id)
	: ID(id)
{
}
