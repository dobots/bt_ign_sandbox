//Include the behaviortree
#include "behaviortree_cpp_v3/bt_factory.h"

#include "template_node.hpp"


using namespace BT;


int main(int argc, char * argv[])
{
    // We use the BehaviorTreeFactory to register our custom nodes
    BehaviorTreeFactory factory;

 
    // Registering a SimpleActionNode using a function pointer.
    // you may also use C++11 lambdas instead of std::bind
    factory.registerNodeType<StartClient>("StartClient"); 


    // IMPORTANT: when the object "tree" goes out of scope, all the 
    // TreeNodes are destroyed
    auto tree = factory.createTreeFromFile("/home/reka/foxy2_ws/src/scenarios/xml/scenario_runner.xml");
    
    // To "execute" a Tree you need to "tick" it.
    // The tick is propagated to the children based on the logic of the tree.
    // In this case, the entire sequence is executed, because all the children
    // of the Sequence return SUCCESS.
    tree.tickRoot();

  return 0;
}
