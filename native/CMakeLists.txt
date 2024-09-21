find_package(Qt6 COMPONENTS WaylandClient)

if(TARGET Qt::WaylandClient AND TARGET Qt::Widgets)
    add_subdirectory(climate)
    add_subdirectory(media)
    add_subdirectory(dashboard)
endif()
