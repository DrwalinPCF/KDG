
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ERROR_H
#define ERROR_H

class Actor;

#include "../lib/MZ/SourceHeader/File.h"
#include "../lib/MZ/SourceHeader/String.h"
#include <cstdio>
#include <ctime>

#ifdef NEXT_ERROR_ESSAGE_ID
#pragma GCC error "my message error"
#endif

#define GET_NEXT_ERROR_MESSAGE_ID ((errorMessagesIdCounter==311-1)?errorMessagesIdCounter+=2:++errorMessagesIdCounter)

namespace ErrorMessages
{
	enum ErrorMessagesEnum
	{
		none,
		
		windowResize,
		windowFullscreen,
		windowWindowed,
		windowCreate,
		windowDestroy,
		windowSwapBuffer,
		
		graphicDrawDebug,
		
		fileInvalid,
		
		pointerActorNotExist,
		
		castingActorIsNotStaticOrDynamic,
		
		unknown = 311
	};
}

#undef GET_NEXT_ERROR_MESSAGE_ID

class Error
{
private:
	
	String className;
	String functionName;
	String message;
	long long int timeSignature;
	
	static File file;
	
public:
	
	inline String GetClassName() const;
	inline String GetFunctionName() const;
	inline String GetMessage() const;
	inline String GetFullMessage() const;
	
	static inline Error Make( const int errorId, const String& errorMessage, const String& classType, const String& functionName );
	static inline void PrepareErrorLogFile( const String& name );
	
	Error();
};

#define MAKE_ERROR( _engineObjectPointer, _errorId, _classType, _errorMessage, _functionName )	\
			_engineObjectPointer->AddError( Error::Make( _errorId, _errorMessage, _classType, _functionName ) );

#endif		// ERROR_H


