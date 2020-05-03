#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "windows.h"

using namespace std;

char* twistWords(const char* str) {
	return (NULL);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int symvols = 0;

	int full_slovo = 1;
	int massiv_of_full_slov[10] = {};

	int schethchik_bukv = 0;
	char peremennaya_dlya_ombena = 0;
	static char stroka[100] = {};
	int len = strlen(stroka);
	cout << "Введите строку: ";
	cin.getline(stroka, 50);
	symvols = strlen(stroka);
	int start = 0;
	int end = symvols - 1;
	for (int i = 0; stroka[i] != '\0'; i++) {
			if (stroka[i] == ' ' || stroka[i] == '\0' || stroka[i] == '\n' || stroka[i] == '\r') {
				symvols++;
				full_slovo++;
				schethchik_bukv = 0;
			}
			else {
				symvols++;
				schethchik_bukv++;
			}
			if (schethchik_bukv >= 6 && full_slovo >= 1) {
				while (start < end) {
						peremennaya_dlya_ombena = stroka[start];
						stroka[start] = stroka[end];
						stroka[end] = (char)peremennaya_dlya_ombena;
						start++;
						end--;
				}
			}
	}
														//Посчитали количество символов   My name is Maxim
	cout << "Обмен элементов: " << stroka << endl;
	cout << "Количество символов: " << symvols << endl;
	cout << "Количество слов: " << full_slovo;

}	
