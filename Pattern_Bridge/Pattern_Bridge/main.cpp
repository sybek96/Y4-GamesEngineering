#include <iostream>
#include "DrawImpl.h"
#include "Player.h"

using namespace std;

int main()
{
	DrawAPI* api = new DrawImpl(); //creating the abstraction
	Character* character = new Player(api); //creating the refinement and pass in the abstraction
	character->Draw(); //draw the character(refinement) by using the DrawImpl (abstraction)
	system("PAUSE");
}