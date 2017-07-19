#pragma once
// an enum for all the different states makes reading the code easier when refering to the key of a state (these are the keys of each state in the binary tree)
namespace StateManagement
{
	enum GameStateTypes { LOADING, GAME, SPLASH, MENU, PAUSE };
}