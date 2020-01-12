# cmake_minimum_required(VERSION 3.0)
# project(hello_world)
# aux_source_directory(. DIR_TOOT_SRCS)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
# add_executable(${PROJECT_NAME} ${DIR_TOOT_SRCS})

aux_source_directory(. EXECUTABLE)
foreach(T_FILE_NAME ${EXECUTABLE})
    get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)
    # message(${EXECUTABLE_NAME})
    add_executable(${EXECUTABLE_NAME} ${T_FILE_NAME})
    target_link_libraries(
        ${EXECUTABLE_NAME}
        leetcode
        ${CMAKE_THREAD_LIBS_INIT}
        GTest::GTest
        GTest::Main
    )
    message(${T_FILE_NAME})
endforeach()
