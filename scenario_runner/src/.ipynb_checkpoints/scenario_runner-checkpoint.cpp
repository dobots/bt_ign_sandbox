//Include the behaviortree
#include "behaviortree_cpp_v3/bt_factory.h"
//Optional, only needed for printing logs or printing the tree structure
#include "behaviortree_cpp_v3/loggers/bt_cout_logger.h"

#include "start_container.hpp"
#include "start_process.hpp"
//#include "start_simple_process.hpp"
#include "stop_container.hpp"
#include "stop_process.hpp"
#include "update_gui.hpp"
#include "wait_for_gui_event.hpp"


using namespace BT;


int main()
{
    // We use the BehaviorTreeFactory to register our custom nodes
    BehaviorTreeFactory factory;

 
    // Registering a ActionNodes 
    factory.registerNodeType<StartContainer>("StartContainer"); 
    factory.registerNodeType<StartProcess>("StartProcess"); 
    //factory.registerNodeType<StartSimpleProcess>("StartSimpleProcess"); 
    factory.registerNodeType<StopContainer>("StopContainer");
    factory.registerNodeType<StopProcess>("StopProcess");  
    factory.registerNodeType<UpdateGui>("UpdateGui"); 
    factory.registerNodeType<WaitForGuiEvent>("WaitForGuiEvent"); 


    // IMPORTANT: when the object "tree" goes out of scope, all the 
    // TreeNodes are destroyed
    auto tree = factory.createTreeFromFile("/user_data/ros_ws/src/behaviortrees_asimovo/scenario_runner/xml/scenario_runner.xml");
    cout<<"main running"<<endl;    
    // This logger prints state changes on console
    //StdCoutLogger logger_cout(tree); //prints log for each node step
    printTreeRecursively(tree.rootNode()); //prints the tree structure
    
    // To "execute" a Tree you need to "tick" it.
    // The tick is propagated to the children based on the logic of the tree.
    // In this case, the entire sequence is executed, because all the children
    // of the Sequence return SUCCESS.
    tree.tickRoot();

  return 0;
}
