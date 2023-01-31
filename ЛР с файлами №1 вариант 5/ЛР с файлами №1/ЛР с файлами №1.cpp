#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	int fig_scob_open=0, fig_scob_close=0;
	ifstream file_out;
	file_out.open("file.txt");
	if (!file_out)
	{
		std::cout << "Файл не подключен!" << std::endl;
		exit(1);
	}
	while (getline(file_out,str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '{')
			{
				fig_scob_open++;
			}
			if (str[i] == '}')
			{
				fig_scob_close++;
			}
		}
	}
	if (fig_scob_open == 0 && fig_scob_close == 0)
	{
		std::cout << "Фигурных скобок нет" << std::endl;
	}
	std::cout << "Количество открывающихся фигурных скобок= " << fig_scob_open << std::endl;
	std::cout << "Количество закрывающихся фигурных скобок= " << fig_scob_close << std::endl;
	file_out.close();
	return 0;
}