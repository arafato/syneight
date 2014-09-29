
#ifndef SYNEIGHT__TEST__XMATRIX__ENTRYOUTOFBOUNDS_HPP
#define SYNEIGHT__TEST__XMATRIX__ENTRYOUTOFBOUNDS_HPP

#include <syneight/test/xmatrix/namespace.hpp>

#include <iostream>
#include <string>

SYNEIGHT__BEGIN__NAMESPACE__XMATRIX;

/**
 * @class Entry_Out_Of_Bounds syneight/test/xmatrix/entry_out_of_bounds.hpp
 *
 * @brief Exception to be thrown in case of operation on undefined matrix coordinates. 
 *
 * Entry_Out_Of_Bounds is used by xmatrix in order to react on access operations 
 * (i.e. getValue, setValue) on undefined matrix coordinates, which is to say outside of 
 * the matrix' dimensions. 
 * It is initialized with three strings: Filename (e.g. instrinsic __FILE__), sourceline 
 * (e.g. intrinsic __LINE__) and a message. 
 * In order to indicate that both dimensions were out of range, parameters givenVal 
 * (coordinate that caused error) and expectVal (maximum allowed
 * dimension) are to be set equally (e.g. 0 and 0).
 * 
 * @nosubgrouping     
 */
class Entry_Out_Of_Bounds 
{
	
/**
 * @name Constructor
 * @{
 */
public:
	/** @brief Entry_Out_Of_Bounds is initialized with three strings: Filename (e.g. instrinsic __FILE__), sourceline 
	 *  (e.g. intrinsic __LINE__) and a message. 
	 *  In order to indicate that both dimensions were out of range, parameters givenVal 
	 *  (coordinate that caused error) and expectVal (maximum allowed dimension) are to be set equally (e.g. 0 and 0).
	 */
	Entry_Out_Of_Bounds(::std::string file, 
						int line, 
						::std::string message, 
						int givenVal, 
						int expectVal);
/**
 * @}
 */
public:
	/// @brief writes exception message, expected and given value to ::std::cout 
	void what();
	
private: 
	/// @brief member variable storing name of file that throwed the exception
	::std::string errFile;
	/// @brief member variable storing line in which exception has been thrown
	int errLine;
	/// @brief member variable storing error message
	::std::string errMesg;
	/// @brief member variable storing value that caused the error (i.e. the coordinate out of range)
	int errGivenVal;
	/// @brief member variable storing expected coordinate value
	int errExpectVal;
};

SYNEIGHT__END__NAMESPACE__XMATRIX;

#endif
// vim:ts=4:sw=4
