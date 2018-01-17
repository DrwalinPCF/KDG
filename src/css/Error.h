
#ifdef ERROR_MESSAGES

#ifndef ERROR_H
#define ERROR_H

#include <string>

namespace ErrorMessages
{
	namespace Window
	{
		
	};
	namespace Physics
	{
		
	};
	namespace Graphic
	{
		
	};
	namespace File
	{
		
	};
	namespace Pointer
	{
		
	};
	namespace Casting
	{
		
	};
};

class Error
{
private:
	
	std::string className;
	std::string functionName;
	std::string message;
	
public:
	
	inline std::string GetClassName() const;
	inline std::string GetFunctionName() const;
	inline std::string GetMessage() const;
	
	template < class T >
	static inline Error Make( const std::string& errorMessage, const T * object, const std::string& functionName );		// T must be class itself, not pointer or reference
	
	Error();
};

#define MAKE_ERROR(engineObjectPointer,classType,errorMessage,objectReference,functionName)	\
			engineObjectPointer->AddError( Error::Make<classType>( errorMessage, objectReference, functionName ) );

#endif		// ERROR_H
#else		// ERROR_MESSAGES

#define MAKE_ERROR(engineObjectPointer,classType,errorMessage,objectReference,functionName)

#endif		// ERROR_MESSAGES


