#include <iostream>
using namespace std;
#include <windows.h>

void heapify(int arr[], int n, int i) {
    int largest = i;             // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;        // Левый дочерний элемент
    int right = 2 * i + 2;       // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше наибольшего элемента на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Рекурсивно применяем heapify к поддереву
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    // Начинаем с последнего родительского узла и вызываем heapify для каждого узла
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    // Извлекаем элементы из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

void print_pyramid(int arr[], int n) {
    cout << "Пирамида:" << endl;

    for (int i = 0; i < n; i++) {
        int level = 0;
        int parentIndex = (i - 1) / 2;

        // Определяем уровень
        int temp = i;
        while (temp > 0) {
            temp = (temp - 1) / 2;
            level++;
        }

        // Определяем левый или правый элемент
        if (i == 0) {
            cout << level << " root " << arr[i] << endl;
        }
        else if (i == 2 * parentIndex + 1) {
            cout << level << " left(" << arr[parentIndex] << ") " << arr[i] << endl;
        }
        else {
            cout << level << " right(" << arr[parentIndex] << ") " << arr[i] << endl;
        }
    }
}


int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Исходный массив: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    heapSort(arr1, n1);
    print_pyramid(arr1, n1);

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nИсходный массив: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    heapSort(arr2, n2);
    print_pyramid(arr2, n2);

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\nИсходный массив: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    heapSort(arr3, n3);
    print_pyramid(arr3, n3);

    return 0;
}
