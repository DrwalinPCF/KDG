
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ERROR_CPP
#define ERROR_CPP

#include "../css/Error.h"


inline String Error::GetClassName() const
{
	return className;
}

inline String Error::GetFunctionName() const
{
	return functionName;
}

inline String Error::GetMessage() const
{
	return message;
}

inline String Error::GetFullMessage() const
{
	if( className != "" )
	{
		return String("Error: method: ") + className + "::" + functionName + "() with message: \"" + message + "\" at time: " + String(timeSignature);
	}
	else
	{
		return String("Error: function: ") + functionName + "() with message: < "  + message + " > at time: " + String(timeSignature);
	}
}

inline Error Error::Make( const int errorId, const String& errorMessage, const String& classType, const String& functionName )
{
	Error error;
	
	error.className = classType;
	error.functionName = functionName;
	
	switch( errorId )
	{
	case ErrorMessages::none:
		error.message = "This is not error";
		break;
	
	case ErrorMessages::windowResize:
		error.message = "Window resize failure";
		break;
	case ErrorMessages::windowFullscreen:
		error.message = "Window setting fullscreen mode failure";
		break;
	case ErrorMessages::windowWindowed:
		error.message = "Window setting windowed mode failure";
		break;
	case ErrorMessages::windowCreate:
		error.message = "Window create failure";
		break;
	case ErrorMessages::windowDestroy:
		error.message = "Window destroying failure";
		break;
	case ErrorMessages::windowSwapBuffer:
		error.message = "Swap buffer failure";
		break;
	
	case ErrorMessages::graphicDrawDebug:
		error.message = "Draw debug failure";
		break;
	
	case ErrorMessages::fileInvalid:
		if( errorMessage != "" )
			error.message = "File failure";
		else
			error.message = "Unknown file failure";
		break;
	
	case ErrorMessages::pointerActorNotExist:
		error.message = "Actor does not exist";
		break;
	
	case ErrorMessages::castingActorIsNotStaticOrDynamic:
		error.message = "Actor can not be dynamical cast to ActorStatic* or ActorDynamic*";
		break;
	
	case ErrorMessages::unknown:
		error.message = "This can not happen";
		break;
	default:
		error.message = "Unknown error";
	}
	
	if( errorMessage != "" )
		error.message += String(" - ") + errorMessage;
	
	file.write( String("\n") + error.GetFullMessage() );
	
	return error;
}

inline void Error::PrepareErrorLogFile( const String& name )
{
	file.open( name.c_str(), "w" );
	if( !file.good() )
	{
		printf( "\ Error log file can not be opened: \"%s\" ", name.c_str() );
		exit(311);
	}
}

Error::Error()
{
	timeSignature = clock();
}

#endif

