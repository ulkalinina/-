#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Базовый класс "Detail" (деталь)
class Detail {
protected:
    // Конструктор protected, чтобы запретить явное создание объектов
    Detail() = default;

public:
    // Виртуальный деструктор для корректного удаления производных объектов
    virtual ~Detail() = default;

    // виртуальный метод для полиморфного поведения
    virtual void show() const = 0;

    // Дружественная функция для создания объектов
    template <typename T, typename... Args>
    friend shared_ptr<T> make_shared_instance(Args&&... args);
};

// Производный класс "Assembly" (сборка), представляющий группу деталей
class Assembly : public Detail {
protected:
    vector<shared_ptr<Detail>> parts;

    // Конструктор protected, чтобы запретить явное создание объектов
    Assembly() = default;

public:
    // Метод для добавления деталей в сборку
    void add_part(shared_ptr<Detail> part) {
        parts.push_back(part);
    }

    // Переопределение метода show()
    void show() const override {
        cout << "Сборка, состоящая из следующих частей:\n";
        for (const auto& part : parts) {
            cout << "  - ";
            part->show();
        }
    }
};

// Производный класс "Screw" (винт) как пример отдельной детали
class Screw : public Detail {
protected:
    Screw() = default;

public:
    void show() const override {
        cout << "Винт\n";
    }
};

// Производный класс "Nut" (гайка) как пример отдельной детали
class Nut : public Detail {
protected:
    Nut() = default;

public:
    void show() const override {
        cout << "Гайка\n";
    }
};

// Производный класс "Bolt" (болт) как пример отдельной детали
class Bolt : public Detail {
protected:
    Bolt() = default;

public:
    void show() const override {
        cout << "Болт\n";
    }
};

// Шаблонная дружественная функция для создания объектов
template <typename T, typename... Args>
shared_ptr<T> make_shared_instance(Args&&... args) {
    struct make_shared_enabler : public T {
        make_shared_enabler(Args&&... args) : T(forward<Args>(args)...) {}
    };
    return make_shared<make_shared_enabler>(forward<Args>(args)...);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Вектор для хранения указателей на объекты типа Detail
    vector<shared_ptr<Detail>> details;

    // Создаем несколько деталей
    auto screw = make_shared_instance<Screw>();
    auto nut = make_shared_instance<Nut>();
    auto bolt = make_shared_instance<Bolt>();

    // Добавляем детали в список для вывода
    details.push_back(screw);
    details.push_back(nut);
    details.push_back(bolt);

    // Создаем сборку, состоящую из винта, гайки и болта
    auto assembly = make_shared_instance<Assembly>();
    assembly->add_part(screw);
    assembly->add_part(nut);
    assembly->add_part(bolt);

    // Добавляем сборку в список
    details.push_back(assembly);


    cout << "Детали:\n";

    // Выводим информацию о каждом объекте
    for (const auto& detail : details) {
        detail->show();
        cout << endl;
    }

    return 0;
}
