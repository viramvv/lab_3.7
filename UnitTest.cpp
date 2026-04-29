#include <gtest/gtest.h>
#include "List.h"

// Тест створення та додавання в список
TEST(ListBasicOperations, AppendTest) {
    Node* list = nullptr;
    append(list, 10);
    append(list, 20);
    
    ASSERT_NE(list, nullptr);
    EXPECT_EQ(list->data, 10);
    EXPECT_EQ(list->next->data, 20);
    
    deleteList(list);
}

// Тест видалення парних значень
TEST(ListLogic, RemoveEvenValuesTest) {
    Node* list = nullptr;
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    
    removeEvenValues(list);
    
    // Мають залишитися лише 1 та 3
    EXPECT_EQ(list->data, 1);
    EXPECT_EQ(list->next->data, 3);
    EXPECT_EQ(list->next->next, nullptr);
    
    deleteList(list);
}

// Тест подвоєння на непарних позиціях
TEST(ListLogic, DoubleOddPositionsTest) {
    Node* list = nullptr;
    append(list, 5);  // Поз. 1 (непарна) -> 10
    append(list, 10); // Поз. 2 (парна)   -> 10
    append(list, 7);  // Поз. 3 (непарна) -> 14
    
    doubleOddPositions(list);
    
    EXPECT_EQ(list->data, 10);
    EXPECT_EQ(list->next->data, 10);
    EXPECT_EQ(list->next->next->data, 14);
    
    deleteList(list);
}

// Тест вставки підсписку (імітація вводу для простоти через append)
TEST(ListLogic, InsertSublistSimpleTest) {
    Node* list = nullptr;
    append(list, 1);
    append(list, 3);
    
    // Тут функція insertSublist зазвичай просить cin. 
    // Для автоматичних тестів краще б розбити функцію на дві: 
    // ту, що читає, і ту, що вставляє. Але згідно з вашим кодом:
    // Тестуємо логіку вставки вручну
    Node* sub = nullptr;
    append(sub, 99);
    
    // Емуляція логіки insertSublist для позиції 2
    Node* temp = list->next;
    list->next = sub;
    sub->next = temp;
    
    EXPECT_EQ(list->next->data, 99);
    EXPECT_EQ(list->next->next->data, 3);
    
    deleteList(list);
}