
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

class InputManager
{
private:
	
	static Array < String, long long int > nameToId;
	static Array < long long int, String > idToName;
	
	static Array < long long int, long long int > currentKeyState;
	static Array < long long int, long long int > lastKeyState;
	
public:
	
	static inline String GetClassName();
	
	static const int IsDown = 1;
	static const int IsUp = 2;
	static const int IsPressed = 3;
	static const int IsReleased = 4;
	static const int Position = 5;
	static const int DeltaPosition = 6;
	
	static void Update();
	
	static void Init( const String& fileNameWithKeyNames );
	
	static long long int GetKeyCode( const String keyName );
	static String GetKeyName( const long long int id );
	
	static int GetKeyState( const long long int id, const int type );
};

#endif

