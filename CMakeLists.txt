cmake_minimum_required(VERSION 3.20)
project(lab14_project)

set(CMAKE_CXX_STANDARD 17)

# Додаємо Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Для Windows/macOS іноді потрібно вимкнути встановлення gtest у систему
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Створюємо бібліотеку з вашою логікою (List.cpp), щоб не дублювати код
add_library(ListLib List.cpp)

# Основна програма
add_executable(lab_14 main.cpp)
target_link_libraries(lab_14 ListLib)

# Тестова програма
add_executable(UnitTest UnitTest.cpp)
target_link_libraries(UnitTest ListLib gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTest)