message(STATUS "Add Executable FaceTimelApp")
add_executable(FaceTimelApp
    include/SDL_fonction.h
    src/SDL.c
    src/SDL_main.c)

target_link_libraries(FaceTimelApp PRIVATE FaceTimelAppUtils)