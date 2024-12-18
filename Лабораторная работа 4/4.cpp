#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Базовый класс "Средство передвижения"
class Vehicle {
public:
    virtual void displayInfo() const = 0; // Чисто виртуальный метод
    virtual ~Vehicle() = default; // Виртуальный деструктор
};

// Класс "Велосипед"
class Bicycle : public Vehicle {
public:
    void displayInfo() const override {
        cout << "Это велосипед." << endl;
    }
};

// Класс "Автомобиль"
class Car : public Vehicle {
public:
    void displayInfo() const override {
        cout << "Это автомобиль." << endl;
    }
};

// Класс "Грузовик"
class Truck : public Vehicle {
public:
    void displayInfo() const override {
        cout << "Это грузовик." << endl;
    }
};

// Шаблонный класс для хранения массива указателей на объекты
template <typename T>
class ArrayStorage {
private:
    vector<T*> storage; // Хранилище указателей на объекты

public:
    void add(T* obj) {
        storage.push_back(obj); // Добавляем указатель в хранилище
    }

    // Перегрузка оператора []
    T* operator[](size_t index) {
        if (index < storage.size()) {
            return storage[index]; // Возвращаем указатель на объект
        }
        return nullptr; // Если индекс выходит за пределы
    }

    size_t size() const {
        return storage.size(); // Возвращаем количество объектов в хранилище
    }
};

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");

    ArrayStorage<Vehicle> vehicleStorage;

    // Создаем объекты различных типов
    Bicycle bike;
    Car car;
    Truck truck;

    // Добавляем объекты в хранилище
    vehicleStorage.add(&bike);
    vehicleStorage.add(&car);
    vehicleStorage.add(&truck);

    // Демонстрируем работу оператора []
    for (size_t i = 0; i < vehicleStorage.size(); ++i) {
        Vehicle* vehicle = vehicleStorage[i];
        if (vehicle) {
            vehicle->displayInfo(); // Вызываем метод displayInfo
        }
    }

    return 0; // Завершение программы
}
