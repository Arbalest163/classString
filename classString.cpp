#include <iostream>
#include<string>
using namespace std;

class String {
	char* m_string;
	int m_size;
	static int counterString;
public:
	String();
	String(const char* string);
	String(int size);
	String(const char* string, int size);
	~String();
	String& setString(const char* string);
	String& setStr();
	char* getString();
	friend ostream& operator<<(ostream& out, const String& string);
	static int getCounterString();
};
int String::counterString{ 0 };
int String::getCounterString() {
	return counterString;
}

ostream& operator<<(ostream& out, const String& string) {
	if (string.m_string == nullptr)
		out << "Пустая строка. " << "	Размер строки: " << string.m_size << endl;
	else
	out << string.m_string << "		Размер строки: " << string.m_size << endl;
	return out;

}
String::String() :String(nullptr, 80) {}
String::String(const char* string):String(string, strlen(string)) {};
String::String(int size):String(nullptr,size) {};
String::String(const char* string, int size) {
	counterString++;
	if (string != nullptr) {
		if (size < strlen(string))
			m_size = strlen(string)+1;
		else  m_size = size+1;
		m_string = new char[m_size];
		strcpy_s(m_string, m_size, string);
	}
	else {
		m_size = size;
		m_string = new char[m_size] {0};
	}
};
String::~String(){
	counterString--;
	delete[] m_string;
	cout << "Деструктор сработал. " << "Осталось строк: " << this->getCounterString() << endl;
}
String& String::setString(const char* string) {
	if (string == nullptr) {
		m_string = nullptr;
		m_size = 80;
		return *this;
	}
	else {
		if (strlen(m_string) < strlen(string)) {
			m_size = strlen(string)+1;
			delete[]m_string;
			m_string = new char[m_size];
			strcpy_s(m_string, m_size, string);
			return *this;
		}
		else {
			strcpy_s(m_string, m_size, string);
			return *this;
		}
	}
}
String& String::setStr() {
	cout << "Введте строку: ";
	char str[255];
	gets_s(str);
	this->setString(str);
	return *this;
}
char* String::getString() {
	return m_string; 
}



int main()                   
{
	system("chcp 1251");
	system("cls");
	String* string1 = new String[2];
	String* string2 = new String(100);
	String* string3 = new String("STRING", 1);
	
	string1[1].setStr();
	cout << *(string1);
	cout << *(string1 + 1);
	cout << *string2;
	cout << *string3;
	delete[] string1;
	delete string2;
	delete string3;



}

