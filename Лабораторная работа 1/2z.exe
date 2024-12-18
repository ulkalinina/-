#include <iostream>
#include <vector>
#include <string>

enum class BookType {
    Fiction,    // Художественная литература
    Technical   // Техническая литература
};

class Book {
private:
    std::string author;
    std::string title;
    BookType type;

public:
    // Пользовательский конструктор с проверкой корректности данных
    Book(const std::string& authorName, const std::string& bookTitle, BookType bookType) {
        if (authorName.empty() || bookTitle.empty()) {
            throw std::invalid_argument("Автор и название книги не могут быть пустыми.");
        }
        author = authorName;
        title = bookTitle;
        type = bookType;
    }

    // Методы доступа для получения информации о книге
    std::string getAuthor() const {
        return author;
    }

    std::string getTitle() const {
        return title;
    }

    BookType getType() const {
        return type;
    }

    // Метод для отображения информации о книге
    void display() const {
        std::cout << "Автор: " << author << ", Название: " << title
            << ", Тип: " << (type == BookType::Fiction ? "Художественная" : "Техническая") << '\n';
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        // Создаем библиотеку в виде вектора книг
        std::vector<Book> library;

        // Наполняем библиотеку книгами
        library.emplace_back("Александр Пушкин", "Евгений Онегин", BookType::Fiction);
        library.emplace_back("Лев Толстой", "Война и мир", BookType::Fiction);
        library.emplace_back("Бьёрн Страуструп", "Язык программирования C++", BookType::Technical);
        library.emplace_back("Эндрю Таненбаум", "Архитектура компьютера", BookType::Technical);

        // Пытаемся добавить книгу без автора или названия (будет выброшено исключение)
        // library.emplace_back("", "Неизвестная книга", BookType::Fiction);

        // Выводим информацию о всех книгах в библиотеке
        std::cout << "Содержимое библиотеки:\n";
        for (const auto& book : library) {
            book.display();
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << '\n';
    }

    return 0;
}
