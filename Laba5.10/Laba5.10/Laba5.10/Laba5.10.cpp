#include <iostream>
#include <string>
#include <Windows.h> 

using namespace std;

// Опис структури для студента
struct Student {
    string name;       // Прізвище та ім'я
    int course;        // Курс
    string group;      // Група
    int birthYear;     // Рік народження
};

int main() {
    // Налаштування кодування для підтримки кирилиці в консолі Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Введіть кількість студентів: ";
    cin >> size;
    cin.ignore(); // Очищення буфера після введення числа

    // Створюємо масив структур (максимум на 100 студентів)
    Student students[100];

    // Введення даних про кожного студента
    for (int i = 0; i < size; i++) {
        cout << "\nСтудент №" << i + 1 << endl;
        cout << "Прізвище та ім'я: ";
        getline(cin, students[i].name);
        cout << "Курс: ";
        cin >> students[i].course;
        cout << "Група: ";
        cin >> students[i].group;
        cout << "Рік народження: ";
        cin >> students[i].birthYear;
        cin.ignore(); // Очищення буфера перед наступним рядочком getline
    }

    // Алгоритм пошуку наймолодшого студента
    // Припускаємо, що перший студент — наймолодший
    int youngestIndex = 0;

    // Проходимо по масиву, шукаючи більший рік народження
    for (int i = 1; i < size; i++) {
        if (students[i].birthYear > students[youngestIndex].birthYear) {
            youngestIndex = i; // Запам'ятовуємо індекс нового наймолодшого
        }
    }

    // Виведення результату
    cout << "\n--- Наймолодший студент ---" << endl;
    cout << "ПІБ: " << students[youngestIndex].name << endl;
    cout << "Курс: " << students[youngestIndex].course << endl;
    cout << "Група: " << students[youngestIndex].group << endl;
    cout << "Рік народження: " << students[youngestIndex].birthYear << endl;

    return 0;
}