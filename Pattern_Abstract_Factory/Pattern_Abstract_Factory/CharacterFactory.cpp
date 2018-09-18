#include "CharacterFactory.h"



CharacterFactory::CharacterFactory()
{
}


CharacterFactory::~CharacterFactory()
{
}

Character * CharacterFactory::CreatePlayer()
{
	return new Player();
}

Character * CharacterFactory::CreateOpponents()
{
	return new Boss();
}
