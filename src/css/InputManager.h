
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../Includer.h"

class InputManager
{
private:
	
	static std::map < std::string, long long int > nameToId;
	static std::map < long long int, std::string > idToName;
	
	static std::map < long long int, long long int > currentKeyState;
	static std::map < long long int, long long int > lastKeyState;
	
public:
	
	static const int IsDown = 1;
	static const int IsUp = 2;
	static const int IsPressed = 3;
	static const int IsReleased = 4;
	static const int Possition = 5;
	static const int DeltaPossition = 6;
	
	static void Update();
	
	static void Init( const std::string& fileNameWithKeyNames );
	
	static long long int GetKeyCode( const std::string keyName );
	static std::string GetKeyName( const long long int id );
	
	static int GetKeyState( const long long int id, const int type );
};

#endif

