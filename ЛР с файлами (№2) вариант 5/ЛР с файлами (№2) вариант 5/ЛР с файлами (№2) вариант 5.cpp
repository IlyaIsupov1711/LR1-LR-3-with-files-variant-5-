#include <string>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class foot 
{
private:
	string name;	  //Имена нападающих
	int num_of_shaib; //Количество заброшенных шайб
	int num_of_pered; //Количество сделанных голевых передач
	int straf_time;   //Заработанное штрафное время
public:
	void Set(string name, int num_of_shaib, int num_of_pered, int straf_time) //Set для приватных полей класса
	{
		this->name = name;
		this->num_of_shaib = num_of_shaib;
		this->num_of_pered = num_of_pered;
		this->straf_time = straf_time;
	}
	int get_straf_time()
	{
		return straf_time;
	}
	int get_num_of_pered()
	{
		return num_of_pered;
	}
	string get_name()
	{
		return name;
	}
	int get_num_of_shaib()
	{
		return num_of_shaib;
	}
	int raz()
	{
		return num_of_shaib + num_of_pered;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	foot foot_cl;
	ifstream file("file.txt"); //Присваивание файла к переменной
	if (!file) //Проверка на подключение файла
	{
		cerr << "Неполучается открыть файл" << endl;
		exit(1);
	}
	string line;
	if (!file.good())
	{
		cout << "Файл не открыт!" << endl;
	}
	else
	{
		int num;
		cout << "Введите число футболистов: ";
		cin >> num;
		int mass2[7];
		int mass_of_shaib[7];
		int mass_of_pered[7];
		int mass_of_rez[7];
		string mass_name[7];
		int max1 = 0, max2 = 0, max3 = 0, max4 = 0;
		for (int i = 0; i<num+1; i++)
		{
			getline(file, line);
			istringstream ss(line);
			string name;
			int num_of_goals, num_of_pered, straf_time;
			ss >> name >> num_of_goals >> num_of_pered >> straf_time;
			foot_cl.Set(name, num_of_goals, num_of_pered, straf_time);
			mass2[i] = foot_cl.get_straf_time();
			mass_name[i] = foot_cl.get_name();
			mass_of_shaib[i] = foot_cl.get_num_of_shaib();
			mass_of_pered[i] = foot_cl.get_num_of_pered();
			mass_of_rez[i] = foot_cl.raz();
			if (mass_of_rez[i] > max1)
			{
				max1 = mass_of_rez[i];
				cout << "Сумма: " << max1 << " " << "Имя: " << mass_name[i] << " " << "Голы: " << mass_of_shaib[i] << " " << "Голевые передачи: " << mass_of_pered[i] << endl;
			}
			if (mass_of_rez[i] > 10 && mass_of_rez[i] < max1)
			{
				max2 = mass_of_rez[i];
				cout << "Сумма: " << max2 << " " << "Имя: " << mass_name[i] << " " << "Голы: " << mass_of_shaib[i] << " " << "Голевые передачи: " << mass_of_pered[i] << endl;
			}
			if (mass_of_rez[i] < max2 && mass_of_rez[i]>10)
			{
				max3 = mass_of_rez[i];
				cout << "Сумма: " << max3 << " " << "Имя: " << mass_name[i] << " " << "Голы: " << mass_of_shaib[i] << " " << "Голевые передачи: " << mass_of_pered[i] << endl;
			}
		}
	}
	file.close();
	return 0;
}