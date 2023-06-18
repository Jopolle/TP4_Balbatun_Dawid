cmake_minimum_required(VERSION 3.25)
project(Robot_Arm)

set(CMAKE_CXX_STANDARD 17)

set(ROBOT_ARM_SOURCES main.cpp robotArm.cpp arm.cpp box.cpp)
add_executable(Robot_Arm ${ROBOT_ARM_SOURCES})

add_executable(SFMLtest SFMLtest.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLtest ${SFML_LIBRARIES})
    target_link_libraries(Robot_Arm ${SFML_LIBRARIES})
endif()
