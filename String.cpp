#include "String.h"


String::String()
{
	
	cString = new char();
	*cString = '\0';
}

String::~String()
{
	delete[] cString;
	cString = nullptr;
}

String::String(const String& obj)
{
	
	int length = 0;

	for (int i = 0; obj.cString[i] != '\0'; i++, length++);

	cString = new char[length + 1];

	for (int i = 0; obj.cString[i] != '\0'; i++)
	{
		cString[i] = obj.cString[i];
	}
	cString[length] = '\0';
}




String::String(const String& obj, int start, int c)
{
	
	cString = new char();
	int size = 0;
	int count = 0;

	for (int i = 0; obj.cString[i] != '\0'; i++)
	{
		if (i == start)
		{
			for (int j = start; count != c; i++, j++, count++)
			{
				if (obj.cString[j] == '\0')
					break;

				cString = regrow(cString, size, obj.cString[j]);
				size++;
			}
		}
	}
	cString = regrow(cString, size, '\0');
}


String::String(const char* arr, int characters)
{
	
	cString = new char[characters + 1];

	for (int i = 0; i < characters; i++)
	{
		if (arr[i] == '\0')
			break;

		cString[i] = arr[i];
	}
	cString[characters] = '\0';
}


String::String(int n, char c)
{
	
	cString = new char[n + 1];

	for (int i = 0; i < n; i++)
	{
		cString[i] = c;
	}
	cString[n] = '\0';
}


int String::length()
{
	int length = 0;

	for (int i = 0; cString[i] != '\0'; i++, length++);

	return length;
}


char String::at(int pos)
{
	for (int i = 0; cString[i] != '\0'; i++)
	{
		if (i == pos)
		{
			return cString[pos]; 
		}
	}

	return '\0'; 
}


String::String(const char* arr)
{

	int length = 0;

	for (int i = 0; arr[i] != '\0'; i++, length++);

	cString = new char[length + 1];

	for (int i = 0; arr[i] != '\0'; i++)
	{
		cString[i] = arr[i];
	}
	cString[length] = '\0';
}

String String::substr(int start, int c)
{
	String temp;

	int size = 0;
	int count = 0;

	for (int i = 0; cString[i] != '\0'; i++)
	{
		if (i == start)
		{
			for (int j = start; count != c; j++, count++)
			{
				if (cString[j] == '\0')
					break;

				temp.cString = regrow(temp.cString, size, cString[j]);
				size++;
			}
		}
	}
	temp.cString = regrow(temp.cString, size, '\0');

	return temp;
}


ostream& operator << (ostream& os, const String& obj)
{
	os << obj.cString;

	return os;
}


void copyArray(char* oldArray, int size, char* newArray)
{
	for (int i = 0; i < size; i++)
	{
		newArray[i] = oldArray[i];
	}
}


char* regrow(char* cString, int size, char c)
{
	char* newArray = new char[size + 1];

	copyArray(cString, size, newArray);

	delete[] cString;
	cString = nullptr;

	newArray[size] = c;

	return newArray;
}





