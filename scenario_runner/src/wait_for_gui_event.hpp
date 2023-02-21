#include "behaviortree_cpp_v3/bt_factory.h"
#include <behaviortree_cpp_v3/action_node.h>

using namespace BT;
using namespace std;


// SyncActionNode (synchronous action) with an input port.
class WaitForGuiEvent : public SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature 
    WaitForGuiEvent(const string& name, const NodeConfiguration& config)
      : SyncActionNode(name, config)
    {
    }
    // It is mandatory to define this static method to list the input ports
    static PortsList providedPorts()
    {
        return { 
           };
    }       
         
    // Override the virtual function tick()
    virtual NodeStatus tick() override
    {      
              
        // print some messages for feedback
        cout << "Wait for gui event node called "<<endl;
        return NodeStatus::SUCCESS;
    }
    

    
};

