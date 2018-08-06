#include<iostream>
using namespace std;

class String{
	public:
	//构造函数
	string (const char* str){
		if(str==NULL)
		{
			m_data = new char[1];
			*m_data = '\0';
		}
		else{
			int len = strlen(str);
			m_data = new char(len+1);
			strcpy(m_data,str);
		}
	}
	//拷贝构造函数，拷贝构造函数是将一个对象赋给另一个新创建的对象
	String(const String& s){
		int len = strlen(s.m_data);
		m_data = new char(len+1);
		strcpy(m_data,s.m_data);
	}
	//赋值运算符重载
	String& operator=(const String& s){
		if(this==&s)
		  return *this;
		
		delete[] m_data;

		int len = strlen(s.m_data);
		m_data = new char(len+1);
		strcpy(m_data,s.m_data);

		return *this;
	}
	//析构函数
	~String(){
		if(m_data)
		  delete[] m_data;
	}
	private:
	char* m_data;
}
