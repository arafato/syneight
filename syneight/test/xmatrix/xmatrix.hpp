
#ifndef SYNEIGHT__TEST__XMATRIX__XMATRIX_HPP
#define SYNEIGHT__TEST__XMATRIX__XMATRIX_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

#include <syneight/test/xmatrix/entry_out_of_bounds.hpp>

SYNEIGHT__BEGIN__NAMESPACE__XMATRIX;
/**
 * @class xmatrix syneight/test/xmatrix/xmatrix.impl.hpp
 *
 * @brief A simple matrix template serving as test unit for unittests. 
 *
 * xmatrix<T> is a template providing operations on matrices of type T. 
 * Most operators concerning addition, subtraction and multiplication
 * are implemented so far. 
 *
 * @nosubgrouping     
 */
template<class T> class xmatrix
{
/**
 * @name type definitions
 * @{
 */
public:
	/// @brief Type definition for an xmatrix of type T (template type).
	typedef xmatrix<T> self;
	/// @brief Type definition for an iterator on vector of type T (template type). Correspcnds matrix row iterator.
	typedef typename ::std::vector<T>::iterator vectorIterator;
	/// @brief Type definition for an iterator on vector of type T (template type) in vector. Corresponds matrix column iterator.
	typedef typename ::std::vector< ::std::vector<T> >::iterator matrixIterator;
	/// @brief Type definition for a vector of vectors of type T (template type).
	typedef typename ::std::vector< ::std::vector<T> > vectorMatrix;

/**
 * @}
 * @name constructor and destructor
 * @{
 */
public:
	xmatrix();
	~xmatrix();
 /**
  * @}
  * @name addition operators
  * @{
  */
public:
	/// @brief Add value of same type and reassign result.
	xmatrix<T>& operator +=(self matrixA);
	/// @brief Add value of respective type and reassign result.
	xmatrix<T>& operator +=(T addVal);
	/// @brief Increment each element in matrix and reassign result.
	xmatrix<T>& operator ++();
	/// @brief Add of same type and return result.
	xmatrix<T> operator +(self& matrixA);
	/// @brief Add value of respective type and return result.
	xmatrix<T> operator +(T addVal);
 /**
  * @}
  * @name subtraction operators
  * @{
  */
public: 
	/// @brief Subtract matrix of same type and reassign result.
	xmatrix<T>& operator -=(self matrixA);
	/// @brief Subtract value of respective type and reassign result.
	xmatrix<T>& operator -=(T addVal);
	/// @brief Decrement each element in matrix and reassign.
	xmatrix<T>& operator --();
	/// @brief Subtracct matrix of same type and return result.
	xmatrix<T> operator -(self matrixA);
	/// @brief Subtract value of respective type and return result.
	xmatrix<T> operator -(T subVal);
 /**
  * @}
  * @name multiplication operators
  * @{
  */
public: 
	/// @brief Multiply with value of respecitve type and return result.
	xmatrix<T> operator *(T lambda);
	/// @brief Multiply with value of respective type and reassign result.
	xmatrix<T>& operator *=(T lambda);
	/// @brief Multiply with matrix of same type and reassign result.
	xmatrix<T>& operator *=(self& matrixA);
	/// @brief Multiply with matrix of same type and return result.
	xmatrix<T> operator *(self& matrixA);
 /**
  * @}
  * @name other operators
  * @{
  */
public: 
	/// @brief Compare with matrix of same type. Returns true if element values and dimensions match, else false.
	bool operator ==(self& matrixA);
 /**
  * @}
  * @name getters and setters
  * @{
  */
	/// @brief Returns matrix element at position (xCoord,yCoord).
	T getValue(unsigned int xCoord, unsigned int yCoord);
	/// @brief Sets matrix element at position (xCoord,yCoord).
	void setValue(unsigned int xCoord, unsigned int yCoord, T setValue);
	/// @brief Returns amount of rows the matrix contains.
	unsigned int getRowNum();
	/// @brief Returns amount of columns the matrix contains.
	unsigned int getColumnNum();
 /**
  * @}
  * @name print matrix to ::std::out
  * @{
  */
public: 
	/// @brief Prints matrix dimensions and element set to ::std::cout. 
	void print();
/**
 * @}
 * @name methods for adding and deleting rows and columns
 * @{
 */
	/// @brief Insert row (vector of corresponding type) at end of matrix. Throws Entry_Out_Of_Bounds exception if dimension (amount of elements) does not match. 
	void addRow(::std::vector<T> rowVector);
	/// @brief Insert row (array of corresponding type) at end of matrix. Throws Entry_Out_Of_Bounds exception if dimension (amount of elements) does not match. 
	void addRow(T rowArray[], unsigned int elNum);
	/// @brief Insert column (vector of corresponding type) at end of matrix. 
	void addColumn(::std::vector<T> colVector);
	/// @brief Insert column (array of corresponding type) at end of matrix.
	void addColumn(T colArray[], unsigned int elNum);
	/// @brief Delete row at position <rowNum> from matrix.
	void delRow(unsigned int rowNum);
	/// @brief Delete column at position <colNum> from matrix.
	void delCol(unsigned int colNum);
/**
 * @}
 */
private:
	/// @brief member variable storing the matrix (vector of vector of template type).	
	vectorMatrix m_matrix;
};

SYNEIGHT__END__NAMESPACE__XMATRIX;

#endif
// vim:ts=4:sw=4
