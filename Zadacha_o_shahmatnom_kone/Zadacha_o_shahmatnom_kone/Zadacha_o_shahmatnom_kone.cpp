#include <iostream>

using namespace std;



int HodKonem(int x, int y)
{
    
    int array[8][8];
    int* point_number_zero = (int*)array;
    *point_number_zero = 0;
    int* array_point = &array[x][y];
    *array_point = 1;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (y == j && x == i) {
                cout << *array_point << "\t";
            }
            else {
                cout << *point_number_zero << "\t";
            }
        }
        cout << endl << endl << endl;
    }

    
    while (x <= 8 && y <= 8) {
        if (x <= 7) {
            *array_point = 2;
            x = x + 1;
            if (y <= 7) {
                y = y + 2;
                HodKonem(x, y);
            }
        }
    }
    system("pause");

    return (NULL);
}

int main()
{
    setlocale(LC_ALL, "rus");

    int x,y;
    char y1 = 1;
    int i, j;
    int arr[8][8];
    int* parr = (int*)arr;
    bool x_bool = true;
    bool y_bool = true;
    bool done = false;
    bool doska = false;

   cout << "Куда бы вы хотели чтобы встал конь?" << endl;
    cout << "Введите значение по вертикали: ";
    cin >> x;
    for (x_bool = true; x_bool != false;) {
        if (x < 0 || x > 8) {
            cout << "Недопустимое значение по вертикали";
            x_bool = false;
            doska = false;
        }
        else if (x > 0 && x < 9) {
            cout << "Введите значение по горизонтали (Писать заглавной буквой): ";
            cin >> y1;
            x_bool = false;
            doska = true;
            done = true;
        }
    }
    if (done == false) {

    }
    else {
        for (y_bool = true; y_bool != false;) {
            if (y1 < 65 || y1 > 72) {
                cout << "Недопустимое значение по горизонтали";
                y_bool = false;
                doska = false;
            }
            else {
                cout << endl;
                y_bool = false;
                done = true;
                doska = true;
            }
        }
        if (doska == false) {

        }
        else if (done == true && doska == true) {
            int button1 = 0;
            char button = y1;
                if (button >= 65 && button <= 72) {
                    for (button = 65; button <= 72; button++) {
                        if (button == y1) {
                        button1 = button - 64;
                        }
                    }
                }
            y = button1;
            if (x_bool == false || y_bool == false) {

            }
            if (done == true) {
                for (i = 1; i <= 8; i++) {
                    for (j = 1; j <= 8; j++) {
                        *parr = 0;
                        if (y == j && x == i) {
                            *parr = 1;
                            cout << *parr << "\t";
                        }
                        else { cout << *parr << "\t"; }
                    }
                    cout << endl << endl << endl;
                }
            }
        }
    }
    system("pause");
    //Встали в выбранную точку
    HodKonem(x, y);


     

}



