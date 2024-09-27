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

# Find required Qt6 packages
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Core Multimedia MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Gui AppManLauncherPrivate)

# Define the media executable target and add the resource file directly to it
qt_add_executable(media
    main.cpp
    images.qrc    # Add the images.qrc file here under the main 'media' target
)

# Add the QML module and other source files for the media target
qt_add_qml_module(media
    URI media
    VERSION 1.0
    QML_FILES
        Main.qml
        ControlMedia.qml
        ListButtonMedia.qml
        ListMedia.qml
        ScreenWithMusic.qml
        SliderMedia.qml
        SpeedMusic.qml
        VideoOutput.qml
        VolumeMusic.qml
    SOURCES
        FunctionModel.h FunctionModel.cpp
        RenderVideo.h RenderVideo.cpp
        SongListController.h SongListController.cpp
        VideoListController.h VideoListController.cpp
        MediaEngine.h MediaEngine.cpp
    RESOURCES
        images.qrc  # Ensure that the images.qrc is only listed under the media target
)

# Set output properties for the media target
set_target_properties(media PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    RUNTIME_OUTPUT_DIRECTORY ../../apps/media
)

# Link the necessary libraries to the media target
target_link_libraries(media
    PRIVATE Qt6::Quick
        Qt6::Core
        Qt6::Gui
        Qt6::Multimedia
        Qt6::AppManLauncherPrivate
)

# Install the media target in the specified directory
install(TARGETS media
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
