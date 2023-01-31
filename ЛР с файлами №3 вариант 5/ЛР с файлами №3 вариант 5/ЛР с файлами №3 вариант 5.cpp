#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <string>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file("file.txt");
	if (!file)
	{
		cout << "Файл не открыт!" << endl;
		exit(1);
	}
	int n;
	cout << "Введите количество чисел в файле: ";
	cin >> n;
	int counter = 0;
	bool yes_no = true;
	for (int i=0; i<n; i++)
	{
		string str;
		file >> str;
		int num;
		try
		{
			num = stoi(str);
			if (num > 0 && num % 2 == 0)
			{
				counter = counter + 1;
			}
		}
		catch (exception e)
		{
			yes_no = false;
			cout << "Ошибка" << endl;
			break;
		}
		//cout << str << endl;
	}
	if (yes_no == true)
	{
		cout << "Количество четных положительных чисел: " << counter << endl;
	}
}