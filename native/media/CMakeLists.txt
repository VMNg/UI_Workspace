
cmake_minimum_required(VERSION 3.16)
project(media LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/applicationmanager/application-features/apps/media")

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Core Multimedia MultimediaWidgets)
find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS AppManLauncherPrivate)

qt_add_executable(media
    main.cpp
)

qt_add_qml_module(media
    URI media
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES ControlMedia.qml
        QML_FILES ListButtonMedia.qml
        QML_FILES ListMedia.qml
        QML_FILES ScreenWithMusic.qml
        QML_FILES SliderMedia.qml
        QML_FILES SpeedMusic.qml
        QML_FILES VideoOutput.qml
        QML_FILES VolumeMusic.qml
        SOURCES FunctionModel.h FunctionModel.cpp
        SOURCES RenderVideo.h RenderVideo.cpp
        SOURCES SongListController.h SongListController.cpp
        SOURCES VideoListController.h VideoListController.cpp
        SOURCES MediaEngine.h MediaEngine.cpp
)

set_target_properties(media PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    RUNTIME_OUTPUT_DIRECTORY ../../apps/media
)
target_link_libraries(media 
    PRIVATE Qt6::Quick    
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt6::Multimedia
        Qt::AppManLauncherPrivate
)

install(TARGETS media
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
