#include <iostream>
int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    // Выделение памяти под массив с помощью new
    int* arr = new int[n];
    // Заполнение массива значениями
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    // Вывод содержимого массива
    std::cout << "Содержимое массива: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    // Вывод адреса начала массива
    std::cout << "Адрес начала массива: " << static_cast<void*>(arr) << std::endl;
    // Вывод расстояния элементов от начала массива
    std::cout << "Расстояние элементов от начала массива в байтах: ";
    for (int i = 0; i < n; ++i) {
        std::cout << i * sizeof(int) << " ";
    }
    std::cout << std::endl;
    // Освобождение памяти с помощью delete[]
    delete[] arr;
    return 0;
}
