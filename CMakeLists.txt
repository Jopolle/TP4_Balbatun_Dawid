cmake_minimum_required(VERSION 3.25)
project(Robot_Arm)

set(CMAKE_CXX_STANDARD 17)



set(ROBOT_ARM_SOURCES main.cpp robotArm.cpp arm.cpp button.h button.cpp)
add_executable(Robot_Arm ${ROBOT_ARM_SOURCES} button.h)

add_executable(SFMLtest SFMLtest.cpp button.h button.cpp)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SFMLtest sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(Robot_Arm sfml-system sfml-window sfml-graphics sfml-audio sfml-network)