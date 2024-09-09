file(REMOVE_RECURSE
  "PBL/Climate/src/Climate.qml"
  "PBL/CustomTabButton.qml"
  "PBL/Dashboard/src/Dashboard.qml"
  "PBL/Main.qml"
  "PBL/Media/images.qrc"
  "PBL/Media/src/ControlMedia.qml"
  "PBL/Media/src/Media.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appPBL_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
