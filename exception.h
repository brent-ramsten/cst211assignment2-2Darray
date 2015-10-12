/*
Brent Ramsten

cst211

assignment #1
*/

//#include<ostream>



#ifndef  exception_H
#define  exception_H

class Exception
{
public:
	Exception();
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();
	Exception &operator=(Exception &rhs);
	//ostream &operator<<(Exception &rhs);
	const char *getMessage() { return m_msg; }
	void setMessage(char *msg);
private:
	char *m_msg;
};


Exception::Exception()
{
	m_msg = "no current message";

}


Exception::Exception(char *msg)
{
	for (unsigned int i = 0; i < strlen(msg); i++)
	{
		m_msg[i] = msg[i];
	}

}

Exception::Exception(const Exception &rhs)
{

	for (unsigned int i = 0; i < strlen(rhs.m_msg); i++)
	{
		m_msg[i] = rhs.m_msg[i];
	}
}

void Exception::setMessage(char *msg)
{
	for (unsigned int i = 0; i < strlen(msg); i++)
	{
		m_msg[i] = msg[i];
	}
	delete[] msg;

}


Exception &Exception::operator=(Exception &rhs)
{
	delete[] m_msg;
	for (unsigned int i = 0; i < strlen(rhs.m_msg); i++)
	{
		m_msg[i] = rhs.m_msg[i];
	}

	return *this;
}

/*
ostream &Exception<INPUT>::operator<<(Exception &rhs)
{
os << rhs.m_msg;

}
*/

//return getmessage in the outstream operator

Exception::~Exception()
{
	delete[] m_msg;
}


#endif
