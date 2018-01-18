
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ERROR_CPP
#define ERROR_CPP

#include "../css/Error.h"


inline std::string Error::GetClassName() const
{
	return className;
}

inline std::string Error::GetFunctionName() const
{
	return functionName;
}

inline std::string Error::GetMessage() const
{
	return message;
}

inline std::string Error::GetFullMessage() const
{
	if( className != "" )
	{
		return std::string("Error: method: ") + className + "::" + functionName + "() with message: \"" + message + "\" at time: " + std::to_string(timeSignature);
	}
	else
	{
		return std::string("Error: function: ") + functionName + "() with message: < "  + message + " > at time: " + std::to_string(timeSignature);
	}
}

inline Error Error::Make( const int errorId, const std::string& errorMessage, const std::string& classType, const std::string& functionName )
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
		error.message += " - " + errorMessage;
	
	file << "\n " << error.GetFullMessage();
	
	return error;
}

inline void Error::PrepareErrorLogFile( const std::string& name )
{
	file.open( name );
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

