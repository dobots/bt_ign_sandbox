#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class StartClient : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    StartClient(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    	//ROS nodes subscribers, publishers, server, clients
    	//node = rclcpp::Node::make_shared("spawn_entity_client");
    }
    


    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
           InputPort<string>("queue_name"),
           InputPort<string>("msg"),
           };
    }
    
     
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {
        string queue_name;
        string msg;
       
        
        //Check whether the required inputs are provided. If not throw an error
        //If some of the inputs are optional, remove this check
        if (!getInput<string> ("queue_name", queue_name)){
            throw BT::RuntimeError("missing required input [queue_name]");
        }
        
        if (!getInput<string> ("msg", msg)) {
            throw BT::RuntimeError("missing required input [msg]");
        }
        
             
        //Send the request to the SpawnEntity service
        /*auto request = make_shared<gazebo_msgs::srv::SpawnEntity::Request>();
        request->name = model_name;
        request->xml = xml_desc;
        request->initial_pose = initial_pose;
        auto result = client_spawn->async_send_request(request);*/

        
        /*if (rclcpp::spin_until_future_complete(node, result) != rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(node->get_logger(), "Unable to call /spawn_entity");
            RCLCPP_INFO(node->get_logger(), "SpawnModel: NodeStatus::FAILURE");
            return BT::NodeStatus::FAILURE;
        }*/
        
               
        // print some messages for feedback
        cout << "Queue name: "<<queue_name << "  msg: "<< msg<<endl;
        return NodeStatus::SUCCESS;
    }
    
    private:
        //shared_ptr<rclcpp::Node> node;
        //rclcpp::Client<gazebo_msgs::srv::SpawnEntity>::SharedPtr client_spawn;
        //rclcpp::Client<gazebo_msgs::srv::GetModelList>::SharedPtr client_model;*/
    
};

