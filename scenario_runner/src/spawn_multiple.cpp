//Include the behaviortree
#include "behaviortree_cpp_v3/bt_factory.h"
#include "rclcpp/rclcpp.hpp"

#include "spawn_model.hpp"

#include <behaviortree_cpp_v3/loggers/bt_zmq_publisher.h>

using namespace BT;


int main(int argc, char * argv[])  
{

    rclcpp::init(argc, argv);
    BehaviorTreeFactory factory; 
    factory.registerNodeType<SpawnModel>("SpawnModel");   
 
    auto tree = factory.createTreeFromFile("/user_data/ros_ws/src/behaviortrees_asimovo/scenario_runner/xml/spawn_shapes.xml");
    
    tree.tickRoot(); 
    rclcpp::shutdown();
  return 0;
}