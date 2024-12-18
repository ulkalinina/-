#include <iostream>
#include <string>

using namespace std;

// Базовый класс sales
class sales {
protected:
    float months[3]; // Массив для хранения продаж за три месяца

public:
    // Метод для ввода данных о продажах
    void getSalesData() {
        cout << "Введите продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> months[i];
        }
    }

    // Метод для вывода данных о продажах
    void putSalesData() const {
        cout << "Продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << months[i] << " руб." << endl;
        }
    }
};

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

// Класс book, наследуемый от Publication и sales
class book : public Publication, public sales {
private:
    int pageCount;

public:
    // Метод для ввода данных
    void getdata() override {
        Publication::getdata(); // вызов метода базового класса Publication
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        cin.ignore(); // очистка входного буфера
        getSalesData(); // вызов метода базового класса Sales для ввода данных о продажах
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata(); // вызов метода базового класса Publication
        cout << "Количество страниц: " << pageCount << endl;
        putSalesData(); // вызов метода базового класса Sales для вывода данных о продажах
    }
};

// Класс type, наследуемый от Publication и sales
class type : public Publication, public sales {
private:
    float recordingTime; // время записи в минутах

public:
    // Метод для ввода данных
    void getdata() override {
        Publication::getdata(); // вызов метода базового класса Publication
        cout << "Введите время записи (в минутах): ";
        cin >> recordingTime;
        cin.ignore(); // очистка входного буфера
        getSalesData(); // вызов метода базового класса Sales для ввода данных о продажах
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata(); // вызов метода базового класса Publication
        cout << "Время записи: " << recordingTime << " минут" << endl;
        putSalesData(); // вызов метода базового класса Sales для вывода данных о продажах
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
