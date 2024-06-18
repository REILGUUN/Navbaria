cmake_minimum_required(VERSION 3.5)

project(Linux-Navbar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------- Find package -----------------------------
#find_package(Qt6 REQUIRED COMPONENTS Widgets)
#target_link_libraries(mytarget PRIVATE Qt6::Widgets)
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
#find_package(Qt REQUIRED COMPONENTS Core Gui)
#find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

set(PROJECT_SOURCES
        main.cpp
)

#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Linux-Navbar
      MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Including.h
        clock.cpp

        Calendar.h
        Calendar.cpp
        Clock.h
        Files.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Linux-Navbar APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")

target_link_libraries(Linux-Navbar PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.

set_target_properties(Linux-Navbar PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
# --------------------- Including -----------------------------

find_package(Qt6 REQUIRED COMPONENTS MultimediaWidgets)
target_link_libraries(Linux-Navbar PRIVATE Qt6::MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)
target_link_libraries(Linux-Navbar PRIVATE Qt6::Multimedia)
find_package(Qt6 REQUIRED COMPONENTS QuickWidgets)
target_link_libraries(Linux-Navbar PRIVATE Qt6::QuickWidgets)

# ---------------------------------------------------------------

include(GNUInstallDirs)
install(TARGETS Linux-Navbar
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Linux-Navbar)
endif()
