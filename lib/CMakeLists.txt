message(STATUS "Add Library FaceTimelAppUtils")
add_library(FaceTimelAppUtils STATIC
  include/BMPFile.h
  include/fichier.h
  include/functions.h
  include/structures.h
  src/BMPFile.c
  src/fichier.c
  src/functions.c)

target_compile_features(FaceTimelAppUtils PRIVATE c_std_99)
target_include_directories(FaceTimelAppUtils PUBLIC include)

message(STATUS "Add Tests FaceTimelAppTests")
add_executable(FaceTimelAppTests tests/tests.c)
include(../cmake/FetchCMocka.cmake)
target_compile_features(FaceTimelAppTests PRIVATE c_std_99)
target_link_libraries(FaceTimelAppTests PRIVATE FaceTimelAppUtils cmocka-static)

enable_testing()
add_test(NAME FaceTimelAppTests COMMAND FaceTimelAppTests)