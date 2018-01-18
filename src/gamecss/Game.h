
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef GAME_H
#define GAME_H

#include "../Includer.h"

class Game
{
private:
	
	Engine * engine;
	
public:
	
	void Init( int * argc, char *** argv );
	
	
	
	void MainLoop();
	
	void Destroy();
	
	Game();
	~Game();
};

#endif

