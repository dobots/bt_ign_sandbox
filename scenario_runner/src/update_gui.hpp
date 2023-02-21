#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class UpdateGui : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    UpdateGui(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }
    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
          InputPort<std::string>("param_containerID"),
          InputPort<std::string>("param_processID"),
           };
    }       
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {      
              
        // print some messages for feedback
        cout << "Update gui node called "<<endl;
        
        Optional<std::string> msg_param_containerID = getInput<std::string>("param_containerID");
        // Check if optional is valid. If not, throw its error
        if (!msg_param_containerID)
        {
            cout<< "No container is running or no containerID is received"<<endl;
        } else{
           string containerID = msg_param_containerID.value();
           cout<< "The following containerID is received: "<< containerID<<endl;
        
        }
        
        string containerID = msg_param_containerID.value();
        
        
        Optional<std::string> msg_param_processID = getInput<std::string>("param_processID");
        // Check if optional is valid. If not, print no process is active
        if (!msg_param_processID)
        {
            cout<< "No process is running or no processID is received"<<endl;
        } else{
           string processID = msg_param_processID.value();
           cout<< "The following processID is received: "<< processID<<endl;
        
        }
        
        return NodeStatus::SUCCESS;
    }
    

    
};

