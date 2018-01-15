
#ifndef MAIN_CPP
#define MAIN_CPP

#include "GameIncluder.h"

int main( int argc, char ** argv )
{
	Game * game = new Game;
	game->Init( &argc, &argv );
	game->MainLoop();
	delete game;
	return 0;
}

#endif

