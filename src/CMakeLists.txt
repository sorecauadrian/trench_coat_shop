cmake_minimum_required(VERSION 3.25)
project(a89_sorecauadrian)

set(CMAKE_PREFIX_PATH "/home/sorecauadrian/Qt/6.5.0/")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
qt6_add_resources(Qt6 COMPONENTS qml.qrc)
add_executable(a89_sorecauadrian
        csv_repository.cpp
        csv_repository.h
        exceptions.cpp
        exceptions.h
        file_repository.cpp
        file_repository.h
        html_repository.cpp
        html_repository.h
        main.cpp
        repository.cpp
        repository.h
        service.cpp
        service.h
        trench_coat.cpp
        trench_coat.h
        ui.cpp
        ui.h
        validator.cpp
        validator.h gui.h gui.cpp main_window.cpp main_window.h admin_widget.h admin_widget.cpp user_widget.h user_widget.cpp)
target_link_libraries(a89_sorecauadrian Qt6::Core Qt6::Gui Qt6::Widgets)
