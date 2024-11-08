You will be writing a Java program  that will create a multi-threaded virtual network simulation that creates a network of N Nodes each with K neighbors.
Nodes will use Java concurrency mechanisms to produce and consume Messages.

The program must be in Java.
You must supply a zip file: Lastname-Firstname-HW5.zip containing the fully implemented .java files
the .jar file that will be used to run the program, and a README.txt file explaining your code.  
Java files must be located in a package called src.  
The compiled program will be testing using command-line execution.  

Unserstanding the writeup:  
Theres a network of Nodes that have neighbors.  
    We will be dealing with a directed graph.  

Messages will be sent between Nodes.  

Inputed arguments:  
(  
seed,  
number of Nodes,  
neighbors,  
MessageBuffer size,  
Total number of messages  
)  

Nodes can receive messages from any Node.  
Nodes can ONLY send messages to neighbors.  

There is a network overlay? I dont know what that is.  

Simulation:
    Spawns Node threads.  
    Node Threads are placed into a Thread Pool.  
    The Thread Pool is array backed.  
    Simulation starts: all Nodes created & ready.  
    All nodes will have start() invoked.

Node:
    Has a unique ID.  
    Array of references to neighbor Nodes.  
    Produce and send M/N total Messages.  
    Sending to neighbors is distributed randomly.  
    Nodes will keep track of counts and sums of messages send and received in total and for each neighboring Node.  


VirtualNetworkSimulation:
    Creates a bunch of nodes that it will run.
    node.setNeighbors() (DONE)

Node:
    MessageBuffer: (DONE)
    Message: (DONE)
    Producer:
    Consumer:

Using ArrayBlockingQueue!
https://docs.oracle.com/javase/7/docs/api/java/util/concurrent/ArrayBlockingQueue.html
As mentioned here on stackoverflow the arrayblockingqueue is perfect for consumer producer interactions.
https://stackoverflow.com/questions/1301691/which-concurrent-queue-implementation-should-i-use-in-java

chmod +x wrap.sh

javac -d . src/*.java
jar cfe Simulation.jar src.VirtualNetworkSimulation -C . src
zip -r Schmitz-William-HW5.zip src Simulation.jar README.txt
java -jar Simulation.jar 100 2 1 10 100

2 1 10 100
2 1 100 1000
2 1 100 10000
2 1 10 999
4 2 10 1200
4 2 10 2400
4 3 100 12000
8 2 100 8000
8 4 100 8000
20 10 1000 20000