#include<iostream>
using namespace std;

class String
{
    char* str;
    int length;
	
public:

   	String(const char* str) 
	{

	 length = strlen(str);
	 this->str = new char[length + 1];
	 
	 for (int i = 0; i < length; i++)
	 {
	 	this->str[i] = str[i];
	 }
	 this->str[length] = '\0';
	 }

	String(int leght)
	{
		str = new char[length + 1];
		str[0] = '\0';
		length = 0;
	}
    
	String(const String& copy)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(copy.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = copy.str[i];
		}
		this->str[length] = '\0';
	}

	~String()
	{
		delete[] this->str;
	}
		
	char* createName(char const* str)
	{
		char* temp = new char[strlen(str) + 1];
		strcpy_s(temp, strlen(str) + 1, str);
		return temp;
	}

	String& setString(const char* string)
	{
		delete[] this->str;
		this->str = createName(string);
		return *this;
	}

	void show()
	{
		cout << "str: " << str << endl;
	}

};

int main()
{
	String one("I wish you");
	String two("A Merry Christmas");
	one.show();
	two.show();

	one.setString("And A");
	two.setString("Happy New Year");
	one.show();
	two.show();

	String copy{ two };
	copy.show();

	return 0;
}


