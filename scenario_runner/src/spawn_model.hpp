#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>
#include "rclcpp/rclcpp.hpp"

#include <ros_ign_interfaces/srv/spawn_entity.hpp>



using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class SpawnModel : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    SpawnModel(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
        node = rclcpp::Node::make_shared("spawn_entity_client");
        client_spawn = node->create_client<ros_ign_interfaces::srv::SpawnEntity>("spawn_entity");
    }
      
    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
           InputPort<string>("model_name"),
           InputPort<string>("file_path"),
           InputPort<string>("x"),
           InputPort<string>("y"),
           InputPort<string>("z"), 
           InputPort<string>("R"),
           InputPort<string>("P"),
           InputPort<string>("Y"),
           InputPort<string>("x_rmax"),
           InputPort<string>("y_rmax"),
           InputPort<string>("z_rmax"),
           InputPort<string>("R_rmax"),
           InputPort<string>("P_rmax"),
           InputPort<string>("Y_rmax"),
           };
    }  
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {   
        string model_name;
        
        //Check whether the required inputs are provided. If not throw an error
        if (!getInput<string> ("model_name", model_name)){
            throw BT::RuntimeError("missing required input [model_name]");
        }
        
        // Waiting for spawn service /save
        while (!client_spawn->wait_for_service(chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for service /spawn_entity.");
                return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(node->get_logger(), "Waiting for service /spawn_entity to appear...");
        }
        
        
        //Send the request to the SpawnEntity service
        //auto request = make_shared<gazebo_msgs::srv::SpawnEntity::Request>();
        //request->name = model_name;
        //request->xml = xml_desc;
        //request->initial_pose = initial_pose;
        //auto result = client_spawn->async_send_request(request);
        
        //if (rclcpp::spin_until_future_complete(node, result) != rclcpp::FutureReturnCode::SUCCESS) {
        //    RCLCPP_ERROR(node->get_logger(), "Unable to call /spawn_entity");
        //    RCLCPP_INFO(node->get_logger(), "SpawnModel: NodeStatus::FAILURE");
        //    return BT::NodeStatus::FAILURE;
        //}
        
         //RCLCPP_INFO(node->get_logger(), "Waiting for result of spawning an entity...");
            
            
        // print some messages for feedback
        cout << "Spawn model: "<< model_name<< " spawned."<<endl;
        RCLCPP_INFO(node->get_logger(), "SpawnModel: NodeStatus::SUCCESS");
        return NodeStatus::SUCCESS;
    }
    private:
        shared_ptr<rclcpp::Node> node;    
        rclcpp::Client<ros_ign_interfaces::srv::SpawnEntity>::SharedPtr client_spawn;

    
};