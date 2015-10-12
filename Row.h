#include "2Darray.h"


template<class T>
class Row : public Array<T>
{
public:
	Row(Array thearray, int row);
	~Row();
	T &operator[](int colmn);
private:
	Array m_array;
	int m_row;
};

template<class T>
Row::Row(const Array &thearray, int row) : m_array(thearray), m_row(row)
{
}
template<class T>
T &Row::operator[](int colmn)
{
	
	return m_array[m_row][colmn];
}

template<class T>
Row::~Row()
{
}







//animejolt.org