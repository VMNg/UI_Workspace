cmake_minimum_required(VERSION 3.16)

project(PBL VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

set(CONFIG_FILE "${CMAKE_CURRENT_SOURCE_DIR}/config.yaml")

qt_add_executable(appPBL
    Media/images.qrc
    main.cpp
    ${CONFIG_FILE}
)

qt_add_qml_module(appPBL
    URI PBL
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES Climate/src/Climate.qml Dashboard/src/Dashboard.qml Media/src/Media.qml Media/src/ControlMedia.qml
    QML_FILES CustomTabButton.qml
    SOURCES Media/src/listmodelcontroller.h Media/src/listmodelcontroller.cpp
    SOURCES Media/enginemedia.h Media/enginemedia.cpp
    RESOURCES Media/images.qrc
    RESOURCES Media/music.qrc
)

target_link_libraries(appPBL
    PRIVATE
        Qt6::Quick
        Qt6::Core
        Qt6::Multimedia
)


if(EXISTS ${CONFIG_FILE})
    add_custom_command(TARGET appPBL POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CONFIG_FILE}
        $<TARGET_FILE_DIR:appPBL>)
else()
    message(WARNING "Configuration file ${CONFIG_FILE} not found!")
endif()

set_target_properties(appPBL PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPBL
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS appPBL
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
