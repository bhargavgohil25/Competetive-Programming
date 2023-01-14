#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class String {
public:
	// default constructor
	String() : res(nullptr), len(0) // this is called initializer list
	{}

	// parameterized constructor
	String(const char *ch) {
		len = strlen(ch);
		res = new char[len + 1];
		strcpy(res, ch);
	}

	// copy constructor
	String(const String& str) {
		len = str.len;
		res = new char[len + 1];
		strcpy(res, str.res);
	}

	// move constructor
	String(const String&& str) {
		len = str.len;
		res = str.res;
		str = NULL;
		str.len = 0;
	}

	// copy assignment operator
	String& operator=(const String& str) {
		// check str3 = str3 -> condition
		// here this is pointing to the object which has called that is str3
		// check for self assignment
		if (this != &str) {
			delete[] res; // delete the memory allocated to it earlier
			len = str.len;
			res = new char[len + 1];
			strcpy(res, str.res);
		}
		return *this;
	}

	// get the length of the string and return
	unsigned int length() {
		return len;
	}

	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, const String& str);

	~String() {
		if (res) {
			delete[] res;
			res = nullptr;
			len = 0;
		}
	}

private:
	char *res;
	unsigned int len;
};

ostream& operator<<(ostream& out, const String& str) {
	// as res cant be accessed as, this function is global
	// a way to get access is from making this function as a friend in String class
	out << str.res;
	return out;
}

istream& operator>>(istream& in, const String& str) {
	// as res cant be accessed as, this function is global
	// a way to get access is from making this function as a friend in String class
	in >> str.res;
	return in;
}

int main() {
	String str1; // default constructor
	String str2 = "Bhargav"; // Parameterized constructor
	String str3 = str1; // copy constructor
	str3 = str2; // copy assignment operator
	int len = str3.length();

	cout << str2 ; // overloading << operator
	cin >> str1;

	// what move does is that, it will copy all the content in str6 from str2
	// and destroy str2
	String str6 = std::move(str2);
}
/*
	constructors are used only when it is initialized
	difference between copy constructor and copy assignment operator
	copy constructor is triggered when we are initializing a new string object
	copy assignment operator is triggered when a string object is already initialized but we are modifying through some operator
*/