#include "List.h"

// 1. Створення нового вузла
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// 2. Додавання в кінець списку (ітеративно)
void append(Node*& head, int value) {
    if (head == nullptr) {
        head = createNode(value);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(value);
    }
}

// 3. Вивід списку на екран (використовуємо cout за вашою вимогою)
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "Список порожній." << std::endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

// 4. Очищення пам'яті (видалення всього списку)
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

// 5. Видалення всіх парних значень (рекурсивно)
void removeEvenValues(Node*& head) {
    if (head == nullptr) return;

    if (head->data % 2 == 0) {
        Node* temp = head;
        head = head->next; // Зв'язуємо попередній вузол з наступним через голову
        delete temp;
        removeEvenValues(head); // Перевіряємо цей же вказівник знову (новий елемент)
    } else {
        removeEvenValues(head->next);
    }
}

// 6. Подвоєння значень на непарних позиціях (рекурсивно)
void doubleOddPositions(Node* head, int index) {
    if (head == nullptr) return;

    if (index % 2 != 0) {
        head->data *= 2;
    }
    doubleOddPositions(head->next, index + 1);
}

// 7. Вставка підсписку в задану позицію
void insertSublist(Node*& head, int pos, int count) {
    Node* sublist = nullptr;
    std::cout << "Введіть " << count << " елементів для підсписку:" << std::endl;
    for (int i = 0; i < count; ++i) {
        int val;
        std::cin >> val;
        append(sublist, val);
    }

    if (sublist == nullptr) return;

    // Якщо вставка в початок
    if (pos <= 1 || head == nullptr) {
        Node* temp = sublist;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = head;
        head = sublist;
        return;
    }

    // Пошук вузла, ПІСЛЯ якого вставляємо
    Node* curr = head;
    for (int i = 1; curr->next != nullptr && i < pos - 1; ++i) {
        curr = curr->next;
    }

    // Знаходимо хвіст підсписку
    Node* subTail = sublist;
    while (subTail->next != nullptr) subTail = subTail->next;

    // Вставляємо підсписок у розрив
    subTail->next = curr->next;
    curr->next = sublist;
}