cmake_minimum_required(VERSION 3.9)
project(QtExperimentation)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH $ENV{QT_DIR})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Sql REQUIRED)

add_executable(QtExperimentation main.cpp classes/KeyedObject.h classes/Utilities.h classes/Person.cpp classes/Person.h classes/Gender.h classes/Car.cpp classes/Car.h classes/House.cpp classes/House.h classes/Association.h classes/EventSource.h classes/EventReceiver.cpp classes/EventReceiver.h classes/Reactor.h classes/Factory.cpp classes/Factory.h classes/Product.cpp classes/Product.h classes/Apple.h classes/Apple.cpp classes/banana.cpp classes/banana.h classes/Formatter.cpp classes/Formatter.h classes/ChangeAction.h)

target_link_libraries(QtExperimentation Qt5::Core Qt5::Widgets Qt5::Sql)
