/*
Brent Ramsten

cst211

assignment #1
*/
#include "exception.h"




#ifndef  array_H
#define  array_H



template<class T>
class Array
{

public:
	Array();
	~Array();

	//standard construction
	Array(int length, int startIndex = 0);
	Array(const Array &dataSet);


	Array &operator=(Array &dataSet);
	Row<T> &operator[](int index);




	int getRow() { return m_row; }
	void setRow(int row);


	int getColmn() { return m_colmn; }
	void setColmn(int colmn);

private:
	int m_row;
	int m_colmn;
	T **m_values;

};


//this is a default constructor with no passed in values which gives default values into the variables
template<class T>
Array<T>::Array()
{
	m_row = 10;
	m_colmn = 0;
	m_values = new T[m_row][m_colmn];
}


//copies all relevent values from the dataSet into the new array
template<class T>
Array<T>::Array(const Array &dataSet)
{
	m_values = new T[dataSet.getLength()];

	//takes all vales in dataSet and inserts them into the new m_values
	for (int i = 0; i < dataSet.getLength(); i++)
	{
		m_values[i] = dataSet.m_values[i];
	}
	m_length = dataSet.m_length;
	m_start_index = dataSet.m_start_index;
}


//the below comment establishes all the m_variables with the construction of the constructor so it is unnecessary to do inside it 
//: m_length(length), m_start_index(startIndex), m_values(new  T[m_length - 1])
//if m_values is not properly 
template<class T>
Array<T>::Array(int row, int colmn) :
m_row(row),
m_colmn(colmn),
m_values(new  T[m_row][m_colmn])
{
	//returns true if m_values has an unacceptable length
	if (!m_values)
	{
		//calls the exception class to give appropriate error message
		Exception("allocation error");



	}



}


//resets the start index
template<class T>
void Array<T>::setRow(int row)
{
	//the purpose of the temporary array is to hold the data in the array
	T *temporay = new T[row][m_colmn];
	for (int i = 0; i < m_colmn; i++)
	{
		for (int idx = 0; idx < row; idx++)
		{
			temporay[idx][i] = m_values[idx][i];
		}

	}

	//then the length is reset
	m_row = row;


	//while the current array is deleted
	delete[][] m_values;

	//sets the m_values variale with the new length that was passed in
	m_values = new T[m_length];
	for (int i = 0; i < m_colmn; i++)
	{
		for (int idx = 0; idx < row; idx++)
		{
			m_values[idx][i] = temporay[idx][i];
		}

	}
	//this then destroys the temporary data
	delete[][] temporay;

}


//resets the length by moving the array into a temporary location
//then deleting the current array and replacing it with the contents of the temporary array
template<class T>
void Array<T>::setColmn(int colmn)
{

	//the purpose of the temporary array is to hold the data in the array
	T *temporay = new T[m_row][colmn];
	for (int i = 0; i < colmn; i++)
	{
		for (int idx = 0; idx < m_row; idx++)
		{
			temporay[idx][i] = m_values[idx][i];
		}
		
	}

	//then the length is reset
	m_colmn = colmn;


	//while the current array is deleted
	delete[][] m_values;

	//sets the m_values variale with the new length that was passed in
	m_values = new T[m_length];
	for (int i = 0; i < colmn; i++)
	{
		for (int idx = 0; idx < m_row; idx++)
		{
			m_values[idx][i] = temporay[idx][i];
		}

	}
	//this then destroys the temporary data
	delete[][] temporay;
}





//this takes both of the array objects from the Array classes
//then it deletes the first object and replaces it with the rhs object
template<class T>
Array<T> &Array<T>::operator=(Array<T> &dataSet)
{
	delete[] m_values;

	//sets the m_values variale with the new length that was passed in
	m_values = new T[dataSet.getRow()][dataSet.getColmn()];

	//takes all vales in dataSet and inserts them into the new m_values
	for (int i = 0; i < dataSet.getRow(); i++)
	{

		for (int idx = 0; idx < dataSet.getColmn(); idx++)
		{
			m_values[idx][i] = dataSet.m_values[idx][i];
		}
		
	}

	return *this;
}

template<class T>
Row<T> &Array<T>::operator[](int index)
{

	//calls exception if passed index is lower than zero or higher then length in relation to start index
	if (0 > index)
	{

		Exception("outside bounds error");
	}


	//this uses the start index to get the appropriate index from the m_values array object
	
	Row<T> line(&this, index)
	return line;
}


//when the Array class hits the destructor it deletes the dynamic memory
template<class T>
Array<T>::~Array()
{
	delete[][]  m_values;
}




#endif