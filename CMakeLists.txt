cmake_minimum_required(VERSION 3.5)
project(clock_test)

### Compile options
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unused-parameter -Wall -Wextra -Wpedantic)
endif()

### Dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

### Target executable
ament_auto_add_library(clock_test SHARED
  src/clock_test.cpp
)

rclcpp_components_register_node(clock_test
  PLUGIN "ClockTest"
  EXECUTABLE clock_test_node
)

ament_auto_package(
        INSTALL_TO_SHARE launch
)
