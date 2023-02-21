#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class StopContainer : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    StopContainer(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }
    
    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
          InputPort<std::string>("param_containerID"),
          OutputPort<std::string>("out_containerID"),
           };
    }       
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {      
              
        // print some messages for feedback
        cout << "Stop container node called "<<endl;
        
        Optional<std::string> msg_param_containerID = getInput<std::string>("param_containerID");
        // Check if optional is valid. If not, throw its error
        if (!msg_param_containerID)
        {
            throw BT::RuntimeError("missing required input [containerID]: ", 
                                   msg_param_containerID.error() );
        }
        
 	string containerID = msg_param_containerID.value();
 	
        // use the method value() to extract the valid message.
        std::cout << "Container stopped with theID: " << containerID << std::endl;
        
        // empty the containerID key/value
        setOutput("out_containerID", "" );
        
        return NodeStatus::SUCCESS;
    }
    

    
};

