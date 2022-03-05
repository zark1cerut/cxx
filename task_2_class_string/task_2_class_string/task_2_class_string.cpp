// task_2_class_string.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана строка символов. 
//Подсчитать, сколько раз в строку входит последний символ, и заменить все пробелы на этот символ.

#include <iostream>
using namespace std;


class String {

public:
	String() 
	{
		str = nullptr;
	}
	String(const char *str)
	{

		int length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++) {

			this->str[i] = str[i];

		}

		this->str[length] = '\0';

	}


	String& operator =(const String& other)
	{
		if (this->str != nullptr) delete[] str;


		int length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++) {

			this->str[i] = other.str[i];

		}

		this->str[length] = '\0';


		return *this;
	}

	String& operator +(const String& other)
	{

		String newStr;

		int thisLen = strlen(this->str);
		int otherLen = strlen(other.str);
		newStr.str = new char[thisLen + otherLen + 1];

		int i = 0;
		for (; i < thisLen; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLen; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLen + otherLen] = '\0'; 

		return newStr;

	}


	String& lastchar(const String& other)
	{
		
		if (this->str != nullptr) delete[] str;
		int length = strlen(other.str);
		char lastch = other.str[length - 1];
		this->str = new char[length/2 + 1];
		
		int count = 0;


		for (int i = 0; i < length; i++) {


			this->str[i] = other.str[i];

			if (other.str[i] == lastch) {
				
				count++;
			}
			if (other.str[i] == ' ') {

				this->str[i] = lastch;

			}
		
		}
		this->str[length] = '\0';



		return *this;
	}




	void Print() {

		cout << str;
	}

	~String()
	{
		delete[] this->str;
	}




private:
	char *str;

};

int main()
{
  
	String str;
	String str2("Hello world. How are you?");
	
	str2.Print();
	cout << endl;
	str.lastchar(str2);
	

	//	str.Print();
	
	

	return 0;
}

