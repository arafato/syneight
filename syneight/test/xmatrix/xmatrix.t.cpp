/*
 *  xmatrix.t.cpp
 *
 */

#ifndef SYNEIGHT__TEST__XMATRIX__XMATRIX_T_HPP
#define SYNEIGHT__TEST__XMATRIX__XMATRIX_T_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

#include <syneight/test/xmatrix/xmatrix.impl.hpp>
#include <syneight/test/xmatrix/entry_out_of_bounds.hpp>
// #include <syneight/base/diagnostics/detail/test_assertion.hpp>

#endif

int main()
{	
//	::std::cout.setf(::std::ios::scientific, ::std::ios::floatfield);	
	
	xmatrix::xmatrix<float> uutA;
	xmatrix::xmatrix<float> uutB;
	xmatrix::xmatrix<float> uutC;
	xmatrix::xmatrix<float> uutD;
	
	float elements1[] = { 1.0,  2.3,  3.0 };
	float elements2[] = { 5.0,  6.0,  7.0 };
	float elements3[] = { 9.0,  1.0,  1.0 };
	float elements4[] = { 3.0,  4.4,  5.0 };
	
	float id1[] = { 1,  0,  0 };
	float id2[] = { 0,  1,  0 };
	float id3[] = { 0,  0,  1 };
	
	float zerofill[] = { 0,  0,  0 };
	
	::std::vector<float> row1(elements1, elements1+3);
	::std::vector<float> row2(elements2, elements2+3);
	::std::vector<float> row3(elements3, elements3+3);
	
	::std::vector<float> idrow1(id1, id1+3);
	::std::vector<float> idrow2(id2, id2+3);
	::std::vector<float> idrow3(id3, id3+3);
	
	::std::vector<float> col1(elements4, elements4+3);
	
	try {
		uutA.addRow(row1);
		uutA.addRow(row2);
		uutA.addRow(row3);
		
		uutC.addRow(row3);	// append rows to matrix
		uutC.addRow(row1);
		uutC.addRow(row2);
	//	uutC.addColumn(col1);
		
		uutD.addRow(zerofill,3);
		uutD.addRow(zerofill,3);
		uutD.addRow(zerofill,3);
		
		::std::cout << ::std::endl;
	
	// match before-after: 	
		uutD.print();	
		uutC.print();
		uutD -= (uutC*2);
		uutD.print();
		uutC.print();
	
		
	/*	uutD=uutC;
			
		::std::cout << "increment: (++)" << ::std::endl;
		++uutD;
		uutD.print();
		::std::cout << "decrement: (--)" << ::std::endl;
		--uutD;
		uutD.print();

		::std::cout << ::std::endl;
		::std::cout << "***********************************************************" << ::std::endl;
		::std::string assert_result;
		if (uutD == uutC) { assert_result = "ASSERTION PASS: --(++uut) == uut"; }		
		else { assert_result = "ASSERTION FAILURE: --(++uut) != uut"; }	
		::std::cout << "TEST_ASSERTION(uutD==uutC) " << assert_result << ::std::endl;
		::std::cout << "***********************************************************" << ::std::endl; 
	*/
	} catch( xmatrix::Entry_Out_Of_Bounds eoob ) {
		eoob.what(); // catch exception
	}
	
	return 0;
}

// vim:ts=4:sw=4
