#include <iostream>
#include <cstdlib>  
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

int speed_snake;



void speed (int* speed_snake_void) {                        //Скорость змеи
    if (*speed_snake_void == 1) {
        *speed_snake_void = 500;
        speed_snake = *speed_snake_void;                    
    }
    else if (*speed_snake_void == 2) {
        *speed_snake_void = 200;
        speed_snake = *speed_snake_void;
    }
    else if (*speed_snake_void == 3) {
        *speed_snake_void = 100;
        speed_snake = *speed_snake_void;
    }
    else if (*speed_snake_void == 4) {
        *speed_snake_void = 50;
        speed_snake = *speed_snake_void;
    }
    else if (*speed_snake_void == 5) {
        *speed_snake_void = 10;
        speed_snake = *speed_snake_void;
    }
    
}

int main()
{
    srand(time(NULL));
    rand(); rand(); rand(); rand();         

    string arr[10][10] = {};                //Массив (само поле)
    string* parr = (string*)arr;            

    int x, y;
    int x_apple, y_apple;
    int i, j, up, low, left, right;
    char clear_zone = 255;
    char full_zone = 258;
    bool done = false;
    bool die = false;

    char way;

    int snake_size = 1;
    char apple = 271;
    bool apple_eaten = false;


    char border_up_down = 205;
    char border_left_right = 186;
    char top_left = 201;
    char top_right = 187;
    char lower_left = 200;
    char lower_right = 188;
    cout << "Enter the start of the snake: " << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << endl << "Way:\n" << " w - up,\n d - right,\n s - down,\n a - left\n";
    cout << "Which way will the snake go: ";
    cin >> way;
    cout << endl;
    cout << "Speed: \n 1 - very slow\n 2 - slow\n 3 - medium\n 4 - fast\n 5 - very fast\n";
    cout << "Enter the speed of the snake: ";
    cin >> speed_snake;
    speed(&speed_snake);
    x_apple = rand() % 7 + 1;
    y_apple = rand() % 7 + 1;
    while (die != true) {
        if (apple_eaten == true) {
            x_apple = rand() % 7 + 1;
            y_apple = rand() % 7 + 1;
            apple_eaten = false;
        }
        Sleep(speed_snake);
        system("cls");
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {                     //j - горизонталь, i - вертикаль
                if (i == 0 && j == 0) {
                    arr[i][j] = top_left;
                    *parr = arr[i][j];
                    cout << arr[i][j] << " ";
                }
                if (i == 9 && j == 0) {
                    arr[i][j] = lower_left;
                    *parr = arr[i][j];
                    cout << *parr << " ";
                }
                if (j == 0 && i == 0) {
                    for (up = 1; up <= 8; up++) {                                           //Верхняя сторона
                        arr[i][j] = border_up_down;
                        *parr = arr[i][j];
                        cout << *parr << " ";
                    }
                    if (up > 8) {
                        cout << top_right << endl;
                    }
                }
                if (j == 0 && i == 9) {
                    for (low = 1; low <= 8; low++) {                                //Нижняя стороная
                        arr[i][j] = border_up_down;
                        *parr = arr[i][j];
                        cout << *parr << " ";
                    }
                    if (low > 8) {
                        cout << lower_right;
                        done = true;
                    }
                }
                if ((j == 0 && i == 0) || (j == 0 && i == 1) ||
                    (j == 0 && i == 2) || (j == 0 && i == 3) ||                                   //Левая сторона
                    (j == 0 && i == 4) || (j == 0 && i == 5) ||
                    (j == 0 && i == 6) || (j == 0 && i == 7) ||
                    (j == 0 && i == 8)) {
                    arr[i][0] = border_left_right;
                    *parr = arr[i][0];
                    cout << *parr << " ";
                    done = true;
                }
                if ((j == 9 && i == 0) || (j == 9 && i == 1) ||
                    (j == 9 && i == 2) || (j == 9 && i == 3) ||                                 //Правая сторона
                    (j == 9 && i == 4) || (j == 9 && i == 5) ||
                    (j == 9 && i == 6) || (j == 9 && i == 7) ||
                    (j == 9 && i == 8)) {
                    arr[i][0] = border_left_right;
                    *parr = arr[i][0];
                    cout << *parr << " ";
                    done = true;
                }
                if (x_apple == j && y_apple == i + 1) {
                    arr[x_apple][y_apple] = apple;
                    *parr = arr[x_apple][y_apple];                              //Появление первого яблока
                    cout << *parr << " ";
                    done = true;
                    if (arr[x_apple][y_apple] == arr[x][y]) {
                        arr[x][y] = clear_zone;
                        j = j + 1;                                              //Съедение яблока
                        *parr = arr[x][y];
                        cout << *parr << " ";
                        apple_eaten = true;
                        snake_size++;
                    }           
                }
                if (x == j && y == i + 1) {
                    arr[i][j] = full_zone;                      //Сама змея
                    *parr = arr[i][j];
                    cout << *parr << " ";
                }
                else if (done == false && i < 9) {              //Чистое поле
                    arr[i][j] = clear_zone;
                    *parr = arr[i][j];
                    cout << *parr << " ";

                }
                done = false;
            }
            cout << endl;
        }
        cout << "Score: " << snake_size - 1;
        if (_kbhit() == true) {                         //Проверка на нажатие клавиши
            way = _getch();                             //Получение нажатой клавиши
        }
       

        switch (way)
        {
        case 'w':
            y = y - 1;
            if (y == 0) {
                y = 9;
            }
            break;
        case 'd':
            x = x + 1;
            if (x == 9) {
                x = 1;
            }
            break;
        case 's':
            y = y + 1;
            if (y == 10) {
                y = 1;
            }
            break;
        case 'a':
            x = x - 1;
            if (x == 0) {
                x = 8;
            }
            break;
        }

    }
    
}

