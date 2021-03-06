#pragma once
#include <string>
#include <sstream>

/**
* Error handling macros.
* Usage example:
*	exceptASSERT(someValue < 0);
*	if (!fileHandle)  exceptTHROW("Could not open file.");
* Catch example:
*	try
*	{
*		//Some code that may throw errors using exceptTHROW and exceptASSERT goes here...
*	}
*	catch (const std::exception &e)
*	{
*	    std::cerr << "Error: " << e.what() << std::endl;
*	}
*	catch ( ... )
*	{
*	    std::cerr << "Unspecified error." << std::endl;
*	}
* Based on concepts by Jeff Cotter - Academy of Interactive Entertainment - 2017
* thanks to Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

#define exceptTHROW( message ) do { \
	std::ostringstream oss; \
    oss << message; \
	/*Remove file path, so we end up with just the file name.*/ \
	const char *name = strrchr( __FILE__, '\\' ); \
	if (name) \
	{ \
		name++; \
	} \
	else if (name == 0) \
	{ \
		/*We may be on an OS that uses the alternate slash for paths.*/ \
		name = strrchr(__FILE__, '/'); \
		if (name) name++; \
	} \
	if (name == 0) name = __FILE__; \
	std::string eMessage = "\"" + oss.str() + "\" File: " + name + ". Line: " + std::to_string(__LINE__) + "."; \
    throw std::runtime_error(eMessage); } while(0)  

#define exceptASSERT( condition ) do { if( !(condition) ) exceptTHROW( "Assertion Failure" ); } while(0)