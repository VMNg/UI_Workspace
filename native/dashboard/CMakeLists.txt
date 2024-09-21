
cmake_minimum_required(VERSION 3.16)
project(dashboard LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/applicationmanager/application-features/apps/dashboard")

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)
find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS AppManLauncherPrivate)

qt_add_executable(dashboard
    main.cpp
)

qt_add_qml_module(dashboard
    URI dashboard
    VERSION 1.0
    QML_FILES
        Main.qml
)

set_target_properties(dashboard PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    RUNTIME_OUTPUT_DIRECTORY ../../apps/dashboard
)
target_link_libraries(dashboard 
    PRIVATE Qt6::Quick    
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::AppManLauncherPrivate
)

install(TARGETS dashboard
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
