cmake_minimum_required(VERSION 3.5)
project(scenario_runner)

# Default to C++17
## if(NOT CMAKE_CXX_STANDARD)
##   set(CMAKE_CXX_STANDARD 17)
## endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
find_package(ros_ign_bridge REQUIRED)
find_package(ros_ign_interfaces REQUIRED)
find_package(ignition-gazebo5 REQUIRED)

set(dependencies
  behaviortree_cpp_v3
  ${OTHER_DEPS}
)  

#Add the executable and name it so you can run your node using ros2 run
add_executable(scenario_runner src/scenario_runner.cpp)
ament_target_dependencies(scenario_runner behaviortree_cpp_v3)

add_executable(spawn_multiple src/spawn_multiple.cpp)
ament_target_dependencies(spawn_multiple behaviortree_cpp_v3 rclcpp ros_ign_interfaces ros_ign_bridge)

install(
  DIRECTORY src xml
  DESTINATION share/${PROJECT_NAME}
)

#Finally, add the install(TARGETS..) section so ros2 run can find your executable
install(TARGETS scenario_runner DESTINATION lib/${PROJECT_NAME})

install(TARGETS spawn_multiple DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
   find_package(ament_lint_auto REQUIRED)
#  # the following line skips the linter which checks for copyrights
#  # uncomment the line when a copyright and license is not present in all source files
   #set(ament_cmake_copyright_FOUND TRUE)
#  # the following line skips cpplint (only works in a git repo)
#  # uncomment the line when this package is not in a git repo
   #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
