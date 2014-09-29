/*
 *  Entry_Out_Of_Bounds.cpp
 *  xmatrix
 *
 */

#include <syneight/test/xmatrix/namespace.hpp>

#include <syneight/test/xmatrix/entry_out_of_bounds.hpp>

SYNEIGHT__BEGIN__NAMESPACE__XMATRIX;

//__ EXCEPTIONS _________________________________________________________
//

Entry_Out_Of_Bounds::Entry_Out_Of_Bounds(::std::string file, 
										 int line, 
										 ::std::string message, 
										 int givenVal, 
										 int expectVal)
{
	errFile			= file;
	errLine			= line;
	errMesg			= message;
	errGivenVal		= givenVal;
	errExpectVal	= expectVal;
}
void Entry_Out_Of_Bounds::what()
{
	::std::cout << errMesg;
	if (errExpectVal != errGivenVal) {
			::std::cout << " [given: " << errGivenVal << ", expected: " << errExpectVal << "]";
	}
	::std::cout << std::endl;
	::std::cout << "In " << errFile << " at line " << errLine << ::std::endl;
}

//
//__ END EXCEPTIONS _____________________________________________________

SYNEIGHT__END__NAMESPACE__XMATRIX;

// vim:ts=4:sw=4
