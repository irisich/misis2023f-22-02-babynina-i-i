# CMakeLists.txt в MyProject/

project(MyProject)

add_executable(lib_example example.cpp)

# Указание пути для поиска заголовочных файлов библиотеки
target_include_directories(lib_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ContentChecker/include)

# Линковка с библиотекой ContentChecker
target_link_libraries(lib_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ContentChecker/lib/ContentChecker.lib)
