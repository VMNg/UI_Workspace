
cmake_minimum_required(VERSION 3.16)
project(mock-dev2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/applicationmanager/mock-dev2")

find_package(Qt6 COMPONENTS AppManMainPrivate)

qt6_am_add_systemui_wrapper(mock-dev2
    CONFIG_YAML am-config.yaml
    EXTRA_FILES apps system-ui
)

add_subdirectory(imports)
add_subdirectory(native)
