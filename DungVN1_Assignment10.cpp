#include<iostream>
using namespace std;

class String
{
public:
	String();
	String(char* str);
	~String();
private:
	char* m_string;
	friend String operator+ (const String&, const String&);
	friend ostream& operator << (std::ostream&, String&);
	friend istream& operator >> (std::istream&, String&);
};


String::String() :m_string() {

};


String::String(char* str) {
	this->m_string = str;
};


String::~String() {

};

/******************************************************
function:       overload operator +
parameter:      2 strings
return:			string_added
description:    add 2 strings
*******************************************************/
String operator + (const String& string1, const String& string2)
{
	String string_added;
	string_added = string1;
	int i;
	int j;
	for (i = 0; string_added.m_string[i] != '\0'; i++);
	for (j = 0; string_added.m_string[j] != '\0'; j++, i++)
	{
		string_added.m_string[i] = string2.m_string[j];
	}
	string_added.m_string[i] = '\0';

	return string_added;
}

/******************************************************
function:       overload operator <<
parameter:      
return:			string out
description:    display string on console
*******************************************************/
ostream& operator << (ostream& out, String& string) {
	out << "String imported is: \n" << string.m_string;
	return out;
};

/******************************************************
function:       overload operator >>
parameter:
return:			string in
description:    input string from keyboard
*******************************************************/
istream& operator >> (istream& in, String& string)
{
	string.m_string = new char[100];
	in.getline(string.m_string,100);
	return in;
}

int main()
{
    String string1, string2, string_added;
    cout << "Enter fisrt string: ";
    cin >> string1;
    cout << string1 << "\n";
    cout << "Enter second string: ";
    cin >> string2;
    cout << string2 << "\n";
    string_added = string1 + string2;
    cout << string_added;
}