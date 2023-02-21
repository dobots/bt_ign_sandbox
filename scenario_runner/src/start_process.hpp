#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class StartProcess : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    StartProcess(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }
    
    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
        //instead of input or output you can call it text, message, or whatever is logical
            InputPort<std::string>("param_containerID"),
            OutputPort<std::string>("out_processID"),
           };
    }   
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {   
    
        Optional<std::string> msg_param_containerID = getInput<std::string>("param_containerID");
        // Check if optional is valid. If not, throw its error
        if (!msg_param_containerID)
        {
            throw BT::RuntimeError("missing required input [containerID]: ", 
                                   msg_param_containerID.error() );
        }
        
 	string containerID = msg_param_containerID.value();
        
        //here we need to call a process in the right container using the containerID to fill this variable with real values    
        string processID ="6443468";  
               
        // print some messages for feedback
        cout << "Start process node called "<<endl;
        
        // the output may change at each tick(). Here we keep it simple.
        setOutput("out_processID", processID );
        cout<< "Process started with the ID: "<< processID<<" in the container: "<< containerID<< endl;
        return NodeStatus::SUCCESS;
    }
    

    
};

