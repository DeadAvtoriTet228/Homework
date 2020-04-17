#include <iostream>

using namespace std;

int main()
{

}



//(1) 
/*
    setlocale(LC_ALL, "Russian");
    int arr[5] = { 1, 2, 3, 4, 5 };
    int* Point_arr = arr;
    int arr2[5] = { *Point_arr };
    for (int i = 0; i < 5; i++) {
        cout << "Помещенный массив: " << *(Point_arr + i);
    }
*/

//(2)
/*
    const int SIZE = 5;
    int arr[SIZE] = { 1, 2, 3, 4, 5 };
    int* Point_arr = arr;
    int Peremennaya_dlya_vzyatiya_znacheniy;
    for (int i = 1; i <= SIZE; i++) {
        Peremennaya_dlya_vzyatiya_znacheniy = *(Point_arr + 5 - i);
        if (i == 5) {
            Peremennaya_dlya_vzyatiya_znacheniy = 1;
        }
        *(Point_arr) = Peremennaya_dlya_vzyatiya_znacheniy;
        cout << *Point_arr;
    }
*/

//(3)
/*
    setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    int arr[SIZE] = { 33, 44, 1, 66, 32 };
    int first_number = arr[0];
    int* Point_arr = arr;
    int arr2[5];
    int Peremennaya_dlya_vzyatiya_znacheniy;
    for (int i = 1; i <= SIZE; i++) {
        Peremennaya_dlya_vzyatiya_znacheniy = *(Point_arr + 5 - i);
        *(Point_arr) = Peremennaya_dlya_vzyatiya_znacheniy;
        if (i == 5) {
            *Point_arr = first_number;
        }
        arr2[i - 1] = { *Point_arr };
        cout << arr2[i - 1];
    }
*/