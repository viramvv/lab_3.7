#include "List.h"
#include <iostream>

using namespace std;

int main() {
    Node* list = nullptr;
    int choice, n, value;

    cout << "=== Лабораторна робота No 14 (Варіант 14) ===" << endl;
    cout << "1. Ввести дані з клавіатури" << endl;
    cout << "2. Зчитати з файлу (input.txt)" << endl;
    cout << "Вибір: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Введіть кількість елементів: ";
        cin >> n;
        cout << "Введіть " << n << " цілих чисел: ";
        for (int i = 0; i < n; ++i) {
            cin >> value;
            append(list, value);
        }
    } else {
        ifstream file("input.txt");
        if (file.is_open()) {
            while (file >> value) {
                append(list, value);
            }
            file.close();
            cout << "Дані зчитано успішно." << endl;
        } else {
            cout << "Помилка: файл не знайдено! Створюємо порожній список." << endl;
        }
    }

    // --- 1. Вивід вхідного списку ---
    cout << "\nВхідний список:" << endl;
    printList(list);

    // --- 2. Видалення парних значень ---
    // Функція працює рекурсивно, як ви і просили в попередніх лабораторних
    cout << "\nВидаляємо всі парні значення..." << endl;
    removeEvenValues(list);
    cout << "Список після видалення парних:" << endl;
    printList(list);

    // --- 3. Подвоєння на непарних позиціях ---
    // Важливо: позиції рахуються як 1, 2, 3... (1 - непарна, 2 - парна)
    cout << "\nПодвоюємо значення на непарних позиціях (1-й, 3-й...)..." << endl;
    doubleOddPositions(list);
    cout << "Список після подвоєння:" << endl;
    printList(list);

    // --- 4. Вставка підсписку ---
    int pos, count;
    cout << "\nВставка підсписку:" << endl;
    cout << "Введіть позицію для вставки: ";
    cin >> pos;
    cout << "Введіть кількість елементів підсписку: ";
    cin >> count;

    // Передаємо параметри у функцію, яка сама запитає значення елементів
    insertSublist(list, pos, count);

    // --- 5. Фінальний результат ---
    cout << "\nВихідний список (фінальний результат):" << endl;
    printList(list);

    // Очищення пам'яті перед завершенням програми
    deleteList(list);
    cout << "\nПам'ять звільнена. Програму завершено." << endl;

    return 0;
}