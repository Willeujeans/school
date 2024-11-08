package src;
import java.util.Random;

public class VirtualNetworkSimulation {
    private Node[] threadPoolOfNodes;
    private Random rng;

    public VirtualNetworkSimulation(Long seed, int N, int K, int B, Long M){
        // Create all Nodes needed
        this.threadPoolOfNodes = new Node[N];
        for(int i = 0; i < N; i++){
            this.threadPoolOfNodes[i] = new Node(String.valueOf(i), seed, M/N, K, B);
        }

        // Create network overlay and give each node their neighbors.
        int[][] networkOverlay = generateOverlay(N, K);
        for(int i = 0; i < N; i++){
            Node[] neighbors = new Node[K];
            for(int j = 0; j < K; j++){
                int index = networkOverlay[i][j];
                neighbors[j] = this.threadPoolOfNodes[index];
            }
            this.threadPoolOfNodes[i].setNeighbors(neighbors);
        }
    }

    public static void main(String[] args) {
        if(args.length == 5){
            Long seed = Long.parseLong(args[0]);
            int N = Integer.parseInt(args[1]);
            int K = Integer.parseInt(args[2]);
            int B = Integer.parseInt(args[3]);
            Long M = Long.parseLong(args[4]);
            // seed, N: number of nodes, K: number of neighbors, B: size of buffer, M: number of messages
            VirtualNetworkSimulation simulation = new VirtualNetworkSimulation(seed, N, K, B, M);
            simulation.startSimulation();
        }else{
            System.out.println("Invalid arguments");
        }
    }

    private int[][] generateOverlay(int N, int K){
        System.out.println("Generating Overlay...");
        int[][] overlay = new int[N][K];
        for (int i = 0; i < N; i++) {
            int neighborIndex = 0;
            for (int j = 0; j < K; j++) {
                if (neighborIndex == i) {
                    neighborIndex++;
                }
                overlay[i][j] = neighborIndex;
                neighborIndex++;
            }
        }
    
        for (int i = 0; i < N; i++) {
            String nodeMessage = "Node " + String.valueOf(i) + " Peer:";
            for (int j = 0; j < K; j++) {
                nodeMessage += " " + String.valueOf(overlay[i][j]);
            }
            System.out.println(nodeMessage);
        }
        return overlay;
    }

    public void startSimulation(){
        for(Node node : this.threadPoolOfNodes){
            node.start();
            try {
                node.join();
            } catch (Exception e) {
            }

        }
        for(Node node : threadPoolOfNodes){
            System.out.println("Node " + node.getNodeID() + " statistics:");
            node.reportSumSent();
            node.reportSumReceived();
            node.reportTotalSent();
            node.reportTotalReceived();
        }
    }
}
