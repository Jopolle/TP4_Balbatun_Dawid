cmake_minimum_required(VERSION 3.25)
project(Robot_Arm)

set(CMAKE_CXX_STANDARD 17)



set(ROBOT_ARM_SOURCES main.cpp robotArm.cpp arm.cpp)
add_executable(Robot_Arm ${ROBOT_ARM_SOURCES})

add_executable(SFMLtest SFMLtest.cpp)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SFMLtest sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(Robot_Arm sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

