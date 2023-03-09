# bt_ign_sandbox



Command: 
source /opt/ros/galactic/setup.bash
ign gazebo -s shapes.sdf -v 4

source /opt/ros/galactic/setup.bash
. install/setup.bash 
$ ros2 run scenario_runner spawn_multiple




https://gazebosim.org/docs/garden/spawn_urdf

gz sim empty.sdf
source /opt/ros/galactic/setup.bash
ign gazebo -s shapes.sdf -v 4


viewer: gazebo.ipynb

ign service -l
ign model --list

source /opt/ros/galactic/setup.bash



    #start websocket 
    os.system('cd /gazebo && nohup ign launch -v 4 websocket.ign &')
    

Service call:
gz service -s /world/empty/create --reqtype gz.msgs.EntityFactory --reptype gz.msgs.Boolean --timeout 1000 --req 'sdf_filename: "/path/to/model.urdf", name: "urdf_model"'

Monday:

1. run behavior tree on Asimovo
2. add spawn function and xml to the bt package - comment out the function
3. call the service command from above
4. add ign service to the header of the spawn function



1. How to download a repo from git to Asimovo?
Use https link, username + developer token

Build the ROS2 workspace:
source /opt/ros/galactic/setup.bash
colcon build
or just a selected package e.g.:
colcon build --packages-select scenario_runner
Source packages:
cd /user-data/ros_ws
. install/setup.bash  

Run the scenario:
ros2 run scenario_runner scenario_runner


2. 
-create an xml with spawn node - copy from scenario_runner repo from github

- create an sdf based on the shapes world: https://github.com/gazebosim/gz-sim/blob/gz-sim7/examples/worlds/shapes.sdf

- create cpp function which calls the xml

- create a spawn function: use input ports name, but change only to print a message

-add these file to the CMakeLists

Command: 
$ ros2 run scenario_runner spawn_multiple

Reply:
$ <model_name> model is spawned.



3. Call the service:

Tab complete doesn't work on ign service call

Service call:
gz service -s /world/empty/create --reqtype gz.msgs.EntityFactory --reptype gz.msgs.Boolean --timeout 1000 --req 'sdf_filename: "/path/to/model.urdf", name: "urdf_model"'

ign service -s /world/shapes/create --reqtype ignition.msgs.EntityFactory --reptype ignition.msgs.Boolean --timeout 1000 --req 'sdf_filename: "/user_data/ros_ws/src/behaviortrees_asimovo/scenario_runner/sdf/cylinder_model.sdf", name: "cylinder_model"'

I can't move the models in the viewer
I can't check which ones are available

ign service -s /world/shapes/create --reqtype ignition.msgs.EntityFactory --reptype ignition.msgs.Boolean --timeout 1000 --req 'sdf_filename: "/user_data/ros_ws/src/behaviortrees_asimovo/scenario_runner/sdf/cylinder_model.sdf", name: "cylinder_model"'


4. add ign service to the header of the spawn function
-doesn't work. We need to start the ros_ign bridge and publish on ROS service

5. start a bridge
ros2 run ros_ign_bridge parameter_bridge /model/vehicle_blue/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist


6. include the ROS service to the header
- galactic doesn't work with c++ 14 anymore, CMakelists.txt needs to be changed to 17.
https://answers.ros.org/question/384114/how-do-you-colcon-build-with-a-specific-c-version/

- add the rclcpp dependency inside the CMakelists.txt in the:
ament_target_dependencies(spawn_multiple behaviortree_cpp_v3 rclcpp)

7. call the bridge from terminal
ros2 run ros_ign_bridge parameter_bridge /keyboard/keypress@std_msgs/msg/Int32@gz.msgs.Int32



7. call the ROS2 service from the node

8. call the bridge from the node
ros2 run ros_ign_bridge parameter_bridge /model/vehicle_blue/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist
ros2 run ros_ign_bridge parameter_bridge /world/shapes/create@ros_ign_interfaces/srv/SpawnEntity]ignition.msgs.EntityFactory
ros2 run ros_ign_bridge parameter_bridge /world/shapes/create@ros_ign_interfaces/EntityFactory]ignition.msgs.EntityFactory

Not working - not implemented on foxy

"The bridge is currently implemented in C++. At this point there's no support for service calls. Its support is limited to only the following message types:"
https://github.com/gazebosim/ros_gz/tree/foxy/ros_ign_bridge

The new version still has only one service implemented; worldcontrol
https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_bridge


Links:
https://gazebosim.org/docs/garden/spawn_urdf
https://docs.ros.org/en/galactic/Tutorials/Advanced/Simulators/Ignition.html
https://gazebosim.org/docs/garden/ros2_integration
https://answers.gazebosim.org//question/26037/how-to-spawn-sdf-object-in-ignition-gazebo/
https://github.com/gazebosim/ros_gz/tree/galactic/ros_ign_gazebo
https://github.com/gazebosim/ros_gz/issues/27
https://campus-rover.gitbook.io/lab-notebook/faq/spawn_model_terminal
https://discourse.ros.org/t/spawning-a-robot-entity-using-a-node-with-gazebo-and-ros-2/9985
https://github.com/ros-simulation/gazebo_ros_pkgs/pull/948
https://github.com/ros-simulation/gazebo_ros_pkgs/wiki/ROS-2-Migration:-Spawn-and-delete#spawn-entity-node
https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_bridge
https://github.com/gazebosim/ros_gz/pull/211

https://github.com/gezp/ros_ign_gazebo_manager/blob/main/src/ign_gazebo_manager.cpp
https://github.com/gezp/ros_ign_gazebo_manager/blob/main/src/service_bridge.hpp
