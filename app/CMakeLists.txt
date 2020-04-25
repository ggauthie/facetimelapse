message(STATUS "Add Executable FaceTimelApp")
add_executable(FaceTimelApp
  include/SDL_fonction.h
  src/SDL.c
  src/SDL_main.c)

include(../cmake/FetchSDL2.cmake)
target_link_libraries(FaceTimelApp PRIVATE FaceTimelAppUtils SDL2-static SDL2main)
target_include_directories(FaceTimelApp PUBLIC include)

function(deploy_res RESOURCE OUTPUT)

  message(STATUS "Copy ${RESOURCE} to ${CMAKE_CURRENT_BINARY_DIR}")
  file(COPY ${RESOURCE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

  add_custom_command(TARGET FaceTimelApp
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${RESOURCE}" "$<TARGET_FILE_DIR:FaceTimelApp>/${OUTPUT}"
    COMMENT "Deploy ${OUTPUT} \n"
  )

endfunction()

deploy_res(${CMAKE_CURRENT_SOURCE_DIR}/res/tiger.bmp tiger.bmp)
deploy_res(${CMAKE_CURRENT_SOURCE_DIR}/res/image.bmp image.bmp)
deploy_res(${CMAKE_CURRENT_SOURCE_DIR}/res/hello_world.bmp hello_world.bmp)