#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class StopProcess : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    StopProcess(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }

    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
          InputPort<std::string>("param_containerID"),
          InputPort<std::string>("param_processID"),
          OutputPort<std::string>("out_processID"),
           };
    }       
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {      
              
        // print some messages for feedback
        cout << "Stop process node called "<<endl;
        
        Optional<std::string> msg_param_containerID = getInput<std::string>("param_containerID");
        // Check if optional is valid. If not, throw its error
        if (!msg_param_containerID)
        {
            throw BT::RuntimeError("missing required input [containerID]: ", 
                                   msg_param_containerID.error() );
        }
        
        string containerID = msg_param_containerID.value();
        
        
        Optional<std::string> msg_param_processID = getInput<std::string>("param_processID");
        // Check if optional is valid. If not, throw its error
        if (!msg_param_processID)
        {
            throw BT::RuntimeError("missing required input [processID]: ", 
                                   msg_param_processID.error() );
        }
        
        string processID = msg_param_processID.value();
        
        cout<< "Process stopped with the ID: "<< processID<<" in the container: "<< containerID<< endl;
        
         // empty the processID key/value
        setOutput("out_processID", "" );
        
        return NodeStatus::SUCCESS;
    }
    

    
};

