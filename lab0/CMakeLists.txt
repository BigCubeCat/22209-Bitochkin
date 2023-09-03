cmake_minimum_required(3.6)

project(lab0)

set(SOURCE_EXE src/main.cpp)

include_directories(src/counter)

add_executable(lab0 ${SOURCE_EXE})	# Создает исполняемый файл с именем main

add_subdirectory(src/counter)				# Добавление подпроекта, указывается имя дирректории

target_link_libraries(lab0 src/counter)

