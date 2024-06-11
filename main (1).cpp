#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY = 1 ручное заполнение
 */
enum SELECT {
    RANDOM = 0,
    MANUALLY = 1
};
/**
 * @brief считывает значение типа int
 * @return считанное значение
 */
int getValue();
/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 */
void fillArray(int** arr, int const rows, int const cols, int const min, int const max);
/**
 * @brief Выводит массив на экран
 * @param arr - массив
 * @param n - кол-во строк
 * @param m - кол-во столбцов
 */
void printArray(int** arr, int const n, int const m);
/**
* @brief заменяет максимальный элемент строки - нулём
* @param arr - массив
* @param rows - кол-во строк массива
* @param cols - кол-во столбцов массива
*/
void replaceMaxWithZero(int** arr, int const rows, int const cols);
/**
* @brief находит кол-во строк, удовлетворяющих условию
* @param arr - массив
* @param rows - кол-во строк массива
* @param cols - кол-во столбцов массива
*/
int getNumberOfRows(int** arr, int const rows, int const cols);
/**
* @brief вставляет в массив нулевые строки
* @param arr - массив
* @param rows - кол-во строк массива
* @param cols - кол-во столбцов массива
*/
int** insertZeroRows(int** arr, int& rows, int const cols);
/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 */
void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max);
/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(int const min, int const max);
/**
 * @brief проверяет правильность введенного размера массива.
 * @param n - размер массива
 */
void checkN(int const n);
/**
 * @brief проверяет диапазон
 * @param arr - массив
 * @param rows - кол-во строк
 */
void delArray(int** arr, int const rows);
/**
 * @brief копирует массив.
 * @param arr - массив
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - скопированный массив
 */
int** copyArray(int** arr, int const rows, int const cols);
/**
 * @brief создает новый массив.
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - новый массив
 */
int** getNewArray(int const rows, int const cols);
/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    cout << "Enter number of rows in array: ";
    int rows = getValue();
    checkN(rows);
    cout << "Enter number of columns in array: ";
    int cols = getValue();
    checkN(cols);
    int** arr = getNewArray(rows, cols);
    cout << "Enter min and max values of range: " << endl;
    int minValue = getValue();
    int maxValue = getValue();
    checkRange(minValue, maxValue);
    cout << "Enter your choice to fill array: " << endl
        << RANDOM << " to fill randomly" << endl
        << MANUALLY << " to fill manually" << endl;
    int choice = getValue();
    switch ((enum SELECT)choice) {
    case RANDOM:
        fillArrayRandom(arr, rows, cols, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, rows, cols, minValue, maxValue);
        break;
    default:
        cout << "Your choice is wrong" << endl;
        return 1;
    }

    cout << "Original array:" << endl;
    printArray(arr, rows, cols);

    int** arr2 = copyArray(arr, rows, cols);
    replaceMaxWithZero(arr2, rows, cols);
    cout << "Array after replacing max elements with zeros:" << endl;
    printArray(arr2, rows, cols);
    delArray(arr2, rows);

    int** arr3 = insertZeroRows(arr, rows, cols);
    cout << "Array after inserting rows of zeros:" << endl;
    printArray(arr3, rows, cols);
    delArray(arr3, rows);

    delArray(arr, rows);

    return 0;
}

int getValue() {
    int value;
    cin >> value;
    if (cin.fail()) {
        cout << "Incorrect input";
        abort();
    }
    return value;
}

void fillArray(int** arr, int const rows, int const cols, int const min, int const max) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << "Enter value for element [" << i << "][" << j << "]: ";
            arr[i][j] = getValue();
        }
    }
}

void printArray(int** arr, int const n, int const m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << setw(4);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void replaceMaxWithZero(int** arr, int const rows, int const cols) {
    for (int i = 0; i < rows; ++i) {
        int maxIndex = 0;
        for (int j = 1; j < cols; ++j) {
            if (arr[i][j] > arr[i][maxIndex]) {
                maxIndex = j;
            }
        }
        arr[i][maxIndex] = 0;
    }
}

int** insertZeroRows(int** arr, int& rows, int const cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        if (arr[i][0] % 3 == 0) {
            ++count;
        }
    }

    int newRows = rows + count;
    int** newArr = getNewArray(newRows, cols);

    for (int i = 0, j = 0; i < rows; ++i, ++j) {
        if (arr[i][0] % 3 == 0) {
            for (int k = 0; k < cols; ++k) {
                newArr[j][k] = 0;
            }
            ++j;
        }
        for (int k = 0; k < cols; ++k) {
            newArr[j][k] = arr[i][k];
        }
    }

    delArray(arr, rows);
    rows = newRows;
    return newArr;
}

void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max) {
    srand(time(0));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void checkRange(int const min, int const max) {
    if (min >= max) {
        cout << "Wrong range entered: " << endl;
        abort();
    }
}

void checkN(int n) {
    if (n <= 0) {
        cout << "Wrong size of array" << endl;
        abort();
    }
}

int** getNewArray(int const rows, int const cols) {
    int** arr = new int* [rows];
    for (size_t i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

int** copyArray(int** arr, int const rows, int const cols) {
    int** newArr = getNewArray(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    return newArr;
}

void delArray(int** arr, int const rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int getNumberOfRows(int** arr, int const rows, int const cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        if (arr[i][0] % 3 == 0) {
            ++count;
        }
    }
    return count;
}
