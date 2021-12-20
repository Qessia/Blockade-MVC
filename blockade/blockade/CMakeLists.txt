# CMakeList.txt: проект CMake для blockade; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (blockade "main.cpp" "Module.h" "Module.cpp" "View.h" "View.cpp" "Controller.h" "Controller.cpp" "main.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
