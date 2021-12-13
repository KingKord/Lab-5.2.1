// вариант 3,18
// Горбатых Александр
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

inline bool isInteger(const string s) // функция для проверка на ЧИСЛО (взял с инета:))
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

void init(int** Mas, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Mas[i][j] = rand() % 10 - 5;
			cout << Mas[i][j] << "\t";
		}
		cout << endl;
	}
}
// та самая функция
int** hren(int** Mas, int n, int m) {
	int** Mas_rez = new int* [n * m];
	int** pmas = Mas;
	int** prez = Mas_rez;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i >= j and n - i > j or i <= j and m - 1 - i <= j) and Mas[i][j] < 0) { // условие на заштрихованную зону и на знак числа

				cout << Mas[i][j] << "\t"; // вывод массива

				prez = pmas;
				prez++;
			}
			else cout << "\t";
			pmas++;


		}
		cout << endl;
	}

	return Mas_rez;
	delete[] Mas_rez;
}


int main() {
	srand(time(0));
	setlocale(0, "ru");
	//
	cout << "Введите размер массива\nN = ";

	// ввод чисел и проверка на ошибки
	// проверка N
	string l;
	cin >> l;
	int n = 1;

	while (true)
	{
		if (!isInteger(l) or n <= 0) { // вывод ошибки 
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
			l = "";
			cin >> l;
		}
		else {
			for (auto c : l) // проверка на ЧИСЛО
				n = stoi(l);
			if (n > 0) {
				break;
			}
			else {
				cout << "Вы ввели некорректное число! Попробуйте еще раз ";
			}
		}
		for (auto c : l) // проверка на ЧИСЛО
			n = stoi(l);
		if (n > 0) {
			break;
		}
		n = 0;

	}
	// проверка М
	cout << "\nM = ";
	l = "";
	cin >> l;
	int m = 1;

	while (true)
	{
		if (!isInteger(l) or m <= 0) { // вывод ошибки 
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
			l = "";
			cin >> l;
		}
		else {
			for (auto c : l) // проверка на ЧИСЛО
				m = stoi(l);
			if (m > 0) {
				break;
			}
			else {
				cout << "Вы ввели некорректное число! Попробуйте еще раз ";
			}
		}
		for (auto c : l) // проверка на ЧИСЛО
			m = stoi(l);
		if (m > 0) {
			break;
		}
		m = 0;

	}
	cout << "-------------------------------------------------------------------------------------------------------\n";


	int** Mas = new int* [n];
	for (int i = 0; i < m; i++) Mas[i] = new int[m];
	init(Mas, n, m);


	cout << "-------------------------------------------------------------------------------------------------------\n";
	// сам массив и вызов функции
	int** sobaka = new int* [m * n];
	sobaka = hren(Mas, n, m);
	// далее идёт удаление

	delete[] sobaka;


	for (int i = 0; i < n; i++)
		delete[] Mas[i];
	delete[] Mas;
	return 0;
}