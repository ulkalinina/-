#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;
    float price;

public:
    // Метод для ввода данных
    virtual void getdata() {
        cout << "Введите название книги: ";
        getline(cin, title);
        cout << "Введите цену книги: ";
        cin >> price;
        cin.ignore(); // очистка входного буфера
    }

    // Метод для вывода данных
    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

// Класс book, наследуемый от Publication
class book : public Publication {
private:
    int pageCount;

public:
    // Метод для ввода данных
    void getdata() override {
        Publication::getdata(); // вызов метода базового класса
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        cin.ignore(); // очистка входного буфера
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata(); // вызов метода базового класса
        cout << "Количество страниц: " << pageCount << endl;
    }
};

// Класс type, наследуемый от Publication
class type : public Publication {
private:
    float recordingTime; // время записи в минутах

public:
    // Метод для ввода данных
    void getdata() override {
        Publication::getdata(); // вызов метода базового класса
        cout << "Введите время записи (в минутах): ";
        cin >> recordingTime;
        cin.ignore(); // очистка входного буфера
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata(); // вызов метода базового класса
        cout << "Время записи: " << recordingTime << " минут" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    book Book;
    type AudioBook;

    cout << "Введите данные для книги:" << endl;
    Book.getdata();
    cout << "\nИнформация о книге:" << endl;
    Book.putdata();

    cout << "\nВведите данные для аудиокниги:" << endl;
    AudioBook.getdata();
    cout << "\nИнформация об аудиокниге:" << endl;
    AudioBook.putdata();

    return 0;
}
