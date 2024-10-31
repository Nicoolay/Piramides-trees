#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Функция для нахождения индекса левого потомка
bool getLeftChildIndex(int currentIndex, int arraySize, int& leftChildIndex) {
    leftChildIndex = 2 * currentIndex + 1;
    return leftChildIndex < arraySize;
}

// Функция для нахождения индекса правого потомка
bool getRightChildIndex(int currentIndex, int arraySize, int& rightChildIndex) {
    rightChildIndex = 2 * currentIndex + 2;
    return rightChildIndex < arraySize;
}

// Функция для нахождения индекса родителя
bool getParentIndex(int currentIndex, int& parentIndex) {
    if (currentIndex == 0) return false;
    parentIndex = (currentIndex - 1) / 2;
    return true;
}

// Функция для печати элемента и его позиции
void printPosition(int index, int arr[], int parentIndex = -1) {
    int level = 0;
    int tempIndex = index;
    while (tempIndex > 0) {
        tempIndex = (tempIndex - 1) / 2;
        level++;
    }
    if (index == 0)
        cout << level << " root " << arr[index] << endl;
    else if (index == 2 * parentIndex + 1)
        cout << level << " left(" << arr[parentIndex] << ") " << arr[index] << endl;
    else if (index == 2 * parentIndex + 2)
        cout << level << " right(" << arr[parentIndex] << ") " << arr[index] << endl;
}

void printPyramid(int arr[], int size) {
    cout << "Пирамида:" << endl;
    for (int i = 0; i < size; i++) {
        int parentIndex;
        getParentIndex(i, parentIndex);
        printPosition(i, arr, parentIndex);
    }
}

void travelPyramid(int arr[], int size) {
    int currentIndex = 0;
    string command;

    do {
        int nextIndex;
        cout << "Вы находитесь здесь: ";
        int parentIndex;
        getParentIndex(currentIndex, parentIndex);
        printPosition(currentIndex, arr, parentIndex);

        cout << "Введите команду: ";
        cin >> command;

        if (command == "up") {
            if (getParentIndex(currentIndex, nextIndex)) {
                currentIndex = nextIndex;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
        }
        else if (command == "left") {
            if (getLeftChildIndex(currentIndex, size, nextIndex)) {
                currentIndex = nextIndex;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }
        }
        else if (command == "right") {
            if (getRightChildIndex(currentIndex, size, nextIndex)) {
                currentIndex = nextIndex;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
        }
        else if (command != "exit") {
            cout << "Ошибка! Неизвестная команда" << endl;
        }
    } while (command != "exit");
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    printPyramid(arr, size);
    travelPyramid(arr, size);

    return 0;
}
