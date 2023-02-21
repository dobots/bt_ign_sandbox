#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class StartContainer : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    StartContainer(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }
      
    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
          OutputPort<std::string>("out_containerID")
           };
    }  
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {   
        //here we need to call the processes to fill this variable with real values   
        string containerID ="13546879";  
            
        // print some messages for feedback
        cout << "Start container node called "<<endl;
        
        // the output may change at each tick(). Here we keep it simple.
        setOutput("out_containerID", containerID );
        cout<< "Container started with the ID: "<< containerID<< endl;
        return NodeStatus::SUCCESS;
    }
    

    
};

