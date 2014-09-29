/*	  
 *  xmatrix.impl.hpp
 *  xmatrix
 *
 */

#ifndef SYNEIGHT__TEST__XMATRIX__XMATRIX_IMPL_HPP
#define SYNEIGHT__TEST__XMATRIX__XMATRIX_IMPL_HPP

#include <syneight/test/xmatrix/namespace.hpp>

#include <syneight/test/xmatrix/xmatrix.hpp>

SYNEIGHT__BEGIN__NAMESPACE__XMATRIX;

////////// IMPLEMENTATION /////////////////////////////////////////////////////////////
//

/**
 * @name constructor and destructor
 * @{
 */
template<class T> 
xmatrix<T>::xmatrix()
{
	// init iterator:
	matrixIterator iterCols = m_matrix.begin();
}

template<class T>  
xmatrix<T>::~xmatrix() { }
/**
 * @}
 */

/** 
 * @name Operators
 * @{
 */

/** 
 * @name Addition operators
 */

/**
 * @brief Add matrix of same type and reassign result. 
 * Iterates through rows and columns of matrix parameter, adding each element to the respective 
 * element in m_matrix. 
 */
template<class T>
xmatrix<T>& xmatrix<T>::operator +=(self matrixA)
{ 	 
	T sumValue;
	
	for(unsigned int rowCounter=0; rowCounter<matrixA.getRowNum(); ++rowCounter) {
		for(unsigned int colCounter=0; colCounter<matrixA.getColumnNum(); ++colCounter) {
			sumValue = getValue(rowCounter,colCounter)+matrixA.getValue(rowCounter,colCounter);
			setValue(rowCounter,colCounter,sumValue);
		}
	}	
	return *this;
}
/**
 * @brief Add value of respective type and reassign result. 
 * Iterates through rows and columns of m_matrix, adding pparameter value to each element of m_matrix. 
 */ 
template<class T>
xmatrix<T>& xmatrix<T>::operator +=(T addVal)
{ 	 
	T sumValue;
	
	for(unsigned int rowCounter=0; rowCounter<getRowNum(); ++rowCounter) {
		for(unsigned int colCounter=0; colCounter<getColumnNum(); ++colCounter) {
			sumValue = getValue(rowCounter,colCounter)+addVal;
			setValue(rowCounter,colCounter,sumValue);
		}
	}
	return *this;
}
/**
 * @brief Icrement each element in matrix and reassign result. 
 * Wraps operator +=(T) by calling it with parameter 1. 
 */
template<class T>
xmatrix<T>& xmatrix<T>::operator ++()
{   
	*this +=(static_cast<T>(1));
	return *this;
}
/**
 * @brief Add matrix of same type and return result. 
 * Wraps operator +=(xmatrix) by calling it with given matrix parameter on a temporary variable. 
 * This is necessary, as this+= would reassign the result. 
 */
template<class T>
xmatrix<T> xmatrix<T>::operator +(self& matrixA)
{
	self tmpMatrix = matrixA;
	tmpMatrix += *this;
	return (tmpMatrix);
}
/**
 * @brief Add value of respective type to matrix and return result. 
 * Wraps operator +=(T) by calling it with given value parameter on a temporary variable. 
 * This is necessary, as this+= would reassign the result. 
 */
template<class T>
xmatrix<T> xmatrix<T>::operator +(T addVal)
{
	self sumMatrix = *this;
	sumMatrix+=addVal;
	return (sumMatrix);
}

/**
 * @}	// end addition operators
 * @name Subtraction operators
 * @{
 */

template<class T>
xmatrix<T>& xmatrix<T>::operator -=(self matrixA)
{ 	 
	T difValue;
	
	for(unsigned int rowCounter=0; rowCounter<matrixA.getRowNum(); ++rowCounter) {
		for(unsigned int colCounter=0; colCounter<matrixA.getColumnNum(); ++colCounter) {
			difValue = getValue(rowCounter,colCounter)-matrixA.getValue(rowCounter,colCounter);
			setValue(rowCounter,colCounter,difValue);
		}
	}	
	return *this;
}

template<class T>
xmatrix<T>& xmatrix<T>::operator -=(T subVal)
{   
	T difValue;
		
	for(unsigned int rowCounter=0; rowCounter<getRowNum(); ++rowCounter) {
		for(unsigned int colCounter=0; colCounter<getColumnNum(); ++colCounter) {
			difValue = getValue(rowCounter,colCounter)-subVal;
			setValue(rowCounter,colCounter,difValue);
		}
	}
	return *this;
}

template<class T>
xmatrix<T>& xmatrix<T>::operator --()
{   
	operator -=(static_cast<T>(1));
	return *this;
}

template<class T>
xmatrix<T> xmatrix<T>::operator -(self matrixA)
{
	self difMatrix = *this;
	difMatrix-=matrixA;
	return (difMatrix);
}

template<class T>
xmatrix<T> xmatrix<T>::operator -(T subVal)
{
	self difMatrix = *this;
	difMatrix -= subVal;
	return (difMatrix);
}

//-- END MINUS-OPERATORS --

//-- MULTIPLICATION-OPERATORS --

template<class T>
xmatrix<T> xmatrix<T>::operator *(T lambda)
{ 	 
	self prodMatrix = *this;
	prodMatrix *= lambda; 
	return (prodMatrix);
}

template<class T>
xmatrix<T>& xmatrix<T>::operator *=(T lambda)
{ 	 
	T prodValue;
	
	for(unsigned int rowCounter=0; rowCounter<getRowNum(); ++rowCounter) {
		for(unsigned int colCounter=0; colCounter<getColumnNum(); ++colCounter) {
			prodValue = lambda*getValue(rowCounter,colCounter);
			setValue(rowCounter,colCounter,prodValue);
		}
	}
	
	return *this;
}

// TODO: Replace BIP algorithm with _working_ Strassen's algorithm
template<class T>
xmatrix<T>& xmatrix<T>::operator *=(self& matrixA)
{
	self tmpMatrix;
	T tmpVal;
	
	// unsigned int rowsA = getRowNum();
	unsigned int colsA = matrixA.getColumnNum();
	unsigned int rowsB = getRowNum();
	unsigned int colsB = getColumnNum();
	
	for(unsigned int rowCounter=0; rowCounter<rowsB; ++rowCounter) {
		::std::vector<T> tmpRow;
		// prepare each row of result matrix: 
		for(unsigned int colCounter=0; colCounter<colsA; ++colCounter) {
			tmpVal = 0;
			// compute each value in row: 
			for(unsigned int valCounter=0; valCounter<colsB; ++valCounter) {
				tmpVal += (getValue(rowCounter,valCounter)*matrixA.getValue(valCounter,colCounter));
			}
			vectorIterator rowIterator = tmpRow.end();
			// add each value to row: 
			tmpRow.insert(rowIterator, tmpVal);
		}
		// add each row to result matrix: 
		tmpMatrix.addRow(tmpRow);
	}
	// override this.matrix with product: 
	matrix = tmpMatrix.matrix;
	return *this;
}

template<class T>
xmatrix<T> xmatrix<T>::operator *(self& matrixA)
{ 
	self tmpMatrix = *this;
	tmpMatrix *= matrixA;
	return (tmpMatrix);
}

//-- END MULTIPLICATION-OPERATORS --

template<class T> 
bool xmatrix<T>::operator ==(self& matrixA)
{ 
	unsigned int rowsA = matrixA.getRowNum();
	unsigned int colsA = matrixA.getColumnNum();
	unsigned int rowsB = getRowNum();
	unsigned int colsB = getColumnNum();
	
	// check primitive differences: 
	if (colsA != colsB || rowsA != rowsB) {
		return false;
	}
	// check value differences: 
	for(unsigned int rowCounter=0; rowCounter<rowsA; ++rowCounter) {
		for(unsigned int colCounter=0; colCounter<colsA; ++colCounter) {
			T valueA = matrixA.getValue(rowCounter,colCounter);
			T valueB = getValue(rowCounter,colCounter);
			if (valueA != valueB) { 
				::std::cout.setf(::std::ios::scientific, ::std::ios::floatfield);
				::std::cout << valueA << ", " << valueB << ::std::endl;
				::std::cout.setf(::std::ios::fixed, ::std::ios::floatfield);
				::std::cout << "row: " << rowCounter << ", column: " << colCounter << ::std::endl;
				return false; 
			}
		}
	}
	// all passed: 
	return true;
}

//__ END OPERATORS ________________________________________________________


//__ STANDARD GETTERS _____________________________________________________
//

template<class T> 
T xmatrix<T>::getValue(unsigned int rowCoord, unsigned int colCoord)
{
	try {
		return (m_matrix[rowCoord][colCoord]);
	} catch (::std::out_of_range oobException) {
		if (colCoord >= getColumnNum()) {
			throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to return value: Requested matrix column out of bounds. ", colCoord, getColumnNum());
		} else if (rowCoord >= getRowNum()) {
			throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to return value: Requested matrix row out of bounds. ", rowCoord, getRowNum());
		} else {
			throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to return value: Both requested matrix coordinates out of bounds. ", 0, 0);
		}	
	}
}

template<class T> 
void xmatrix<T>::setValue(unsigned int rowCoord, unsigned int colCoord, T setVal)
{
	try {
		m_matrix[rowCoord][colCoord] = setVal;
	} catch (::std::out_of_range oobException) {
		if (colCoord >= getColumnNum()) {
			throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to set value: Requested matrix column out of bounds. ", colCoord, getColumnNum());
		} else if (rowCoord >= getRowNum()) {
			throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to set value: Requested matrix row out of bounds. ", rowCoord, getRowNum());
		} else {
			throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to set value: Both requested matrix coordinates out of bounds. ", 0, 0);
		}
	}
}

template<class T> 
unsigned int xmatrix<T>::getRowNum()
{
	return static_cast<unsigned int>(m_matrix.size());
}
template<class T> 
unsigned int xmatrix<T>::getColumnNum()
{
	if (m_matrix.size() > 0) { 
		unsigned int size = (static_cast<unsigned int>(m_matrix[0].size())); 
		return size;
	}
	return 0; 
}

//
//__ END STANDARD GETTERS__________________________________________________

template<class T> 
void xmatrix<T>::print()
{
	::std::cout << "current dimension: (" << getColumnNum() << "x" << getRowNum() << "): " << ::std::endl;
	for (unsigned int rowCounter=0; rowCounter < getRowNum(); ++rowCounter) {
		for (unsigned int colCounter=0; colCounter < getColumnNum(); ++colCounter) {
			::std::cout << m_matrix[rowCounter][colCounter] << " ";
		}
		::std::cout << ::std::endl;
	}
}


//__ ADD / DELETE _________________________________________________________
//

/** Add row to matrix, i.e. append new vector<int> to matrix vector. */
template<class T> 
void xmatrix<T>::addRow(::std::vector<T> rowVector)
{
	if (rowVector.size() == getColumnNum() || getRowNum()==0) {	// compare row vector index with index of 
									// row in matrix. If matrix is empty (getRowNum()==0),
									// add row. 
		matrixIterator iterPos = m_matrix.end();		// jump to end of matrix (vector)
		m_matrix.insert(iterPos, rowVector);			// insert row at end of matrix
	// in case of index mismatch, throw exception: 
	} else {
		throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to append row: Vector size doesn't match. ", rowVector.size(), m_matrix[0].size());
	}
}
/** Overloading and wrapping of addRow for arrays. */
template<class T> 
void xmatrix<T>::addRow(T rowArray[], unsigned int elNum)
{
	::std::vector<T> row(rowArray, rowArray+elNum);
	addRow(row);
}

/** Add column to matrix, i.e. append entry to every row: */
template<class T> 
void xmatrix<T>::addColumn(::std::vector<T> colVector)
{	
	for (unsigned int rowCounter=0; rowCounter <= getRowNum(); ++rowCounter) {
		vectorIterator iterPos = m_matrix[rowCounter].end();
		matrix[rowCounter].insert(iterPos, colVector[rowCounter]);
	}
} 
/** Overloading and wrapping of addColumn for arrays. */
template<class T> 
void xmatrix<T>::addColumn(T colArray[], unsigned int elNum)
{	
	::std::vector<T> col(colArray, colArray+elNum);
	addColumn(col);
}

/** Delete row from matrix. */
template<class T> 
void xmatrix<T>::delRow(unsigned int rowNum)
{
	try {
		vectorIterator iterPos = m_matrix.begin()+rowNum;
		matrix.erase(iterPos);
	} catch(::std::out_of_range oor) {
		throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to delete row: Index out of bounds. ", rowNum, getRowNum());
	}
}
/** Delete column from matrix. */
template<class T> 
void xmatrix<T>::delCol(unsigned int colNum)
{
	if (colNum <= getColumnNum()) {
		// note: iterpos does not refer to vector< vector<T> >, as it is operating on a single vector (column)
		for (unsigned int rowCounter=0; rowCounter < m_matrix.size(); ++rowCounter) {
			vectorIterator iterPos = m_matrix[rowCounter].begin()+colNum;
			m_matrix[rowCounter].erase(iterPos);
		}
	} else {
		throw Entry_Out_Of_Bounds(__FILE__, __LINE__, "Unable to delete column: Index out of bounds. ", colNum, getColumnNum());
	}
}

// 
//__ END ADD/DELETE _____________________________________________________

SYNEIGHT__END__NAMESPACE__XMATRIX;

#endif
// vim:ts=4:sw=4
