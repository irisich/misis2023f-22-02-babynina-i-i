cmake_minimum_required(VERSION 3.10)
project(ContentChecker)

# Настройка C++ компилятора
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include("D:/oop/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_TOOLCHAIN_FILE "D:/oop/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Найти пакеты OpenCV и Tesseract
find_package(OpenCV REQUIRED)
find_package(Tesseract REQUIRED)

# Включение заголовочных файлов и библиотек
include_directories(${OpenCV_INCLUDE_DIRS} ${Tesseract_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS} ${Tesseract_LIBRARIES})

# Добавление исполняемого файла
add_executable(ContentChecker ContentChecker.cpp)

# Линковка с библиотеками
target_link_libraries(ContentChecker ${OpenCV_LIBS} ${Tesseract_LIBRARIES})
