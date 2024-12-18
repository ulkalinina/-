#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Base {
public:
    virtual ~Base() {}

    virtual void show() const {
        cout << "I'm a Base object." << endl;
    }
};

class Derived : public Base {
public:
    void show() const override {
        cout << "I'm a Derived object." << endl;
    }
};

class Storage {
private:
    vector<shared_ptr<Base>> storage; // Используем shared_ptr для управления памятью

public:
    void add(shared_ptr<Base> obj) {
        storage.push_back(obj); // Добавляем объект в хранилище
    }

    void displayAll() const {
        for (const auto& obj : storage) {
            obj->show(); // Вызов метода show для каждого объекта
        }
    }

    void clearStorage() {
        storage.clear(); // Очищаем хранилище, освобождая ресурсы
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    Storage storage;

    for (int i = 0; i < 10; i++) { // Генерируем 10 объектов
        int randomNumber = rand();
        if (randomNumber % 2 == 0) { // Четное число создает Base
            shared_ptr<Base> basePtr = make_shared<Base>();
            storage.add(basePtr);
        }
        else { // Нечетное число создает Derived
            shared_ptr<Base> derivedPtr = make_shared<Derived>();
            storage.add(derivedPtr);
        }
    }

    // Показать все объекты в хранилище
    storage.displayAll();

    // Очистить хранилище перед завершением программы
    storage.clearStorage();

    return 0; // Завершение программы
}
