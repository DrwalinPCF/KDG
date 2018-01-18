
#ifndef ERROR_H
#define ERROR_H

class Actor;

#include <string>
#include <fstream>
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
	
	std::string className;
	std::string functionName;
	std::string message;
	long long int timeSignature;
	
	static std::ofstream file;
	
public:
	
	inline std::string GetClassName() const;
	inline std::string GetFunctionName() const;
	inline std::string GetMessage() const;
	inline std::string GetFullMessage() const;
	
	static inline Error Make( const int errorId, const std::string& errorMessage, const std::string& classType, const std::string& functionName );
	static inline void PrepareErrorLogFile( const std::string& name );
	
	Error();
};

#define MAKE_ERROR( _engineObjectPointer, _errorId, _classType, _errorMessage, _functionName )	\
			_engineObjectPointer->AddError( Error::Make( _errorId, _errorMessage, _classType, _functionName ) );

#endif		// ERROR_H


