package src;

import java.util.Random;

public class VirtualNetworkSimulation {
    private Node[] threadPoolOfNodes;
    private Random rng;
    private Long messagePerNodeCount = 0L;

    public VirtualNetworkSimulation(Long seed, int N, int K, int B, Long M) {
        // Create all Nodes needed
        this.messagePerNodeCount = M / N;
        this.threadPoolOfNodes = new Node[N];
        for (int i = 0; i < N; i++) {
            this.threadPoolOfNodes[i] = new Node(String.valueOf(i), seed, M / N, K, B);
        }

        // Create network overlay and give each node their neighbors.
        int[][] networkOverlay = generateOverlay(N, K);
        for (int i = 0; i < N; i++) {
            Node[] neighbors = new Node[K];
            for (int j = 0; j < K; j++) {
                int index = networkOverlay[i][j];
                neighbors[j] = this.threadPoolOfNodes[index];
            }
            this.threadPoolOfNodes[i].setNeighbors(neighbors);
        }
    }

    public static void main(String[] args) {
        if (args.length == 5) {
            Long seed = Long.parseLong(args[0]);
            int N = Integer.parseInt(args[1]);
            int K = Integer.parseInt(args[2]);
            int B = Integer.parseInt(args[3]);
            Long M = Long.parseLong(args[4]);
            VirtualNetworkSimulation simulation = new VirtualNetworkSimulation(seed, N, K, B, M);
            simulation.startSimulation();
        } else {
            System.out.println("Invalid arguments");
        }
    }

    private int[][] generateOverlay(int N, int K) {
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

    public void startSimulation() {
        for (Node node : this.threadPoolOfNodes) {
            node.start();
        }
        while (!allNodesDone()) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        try {
            Thread.sleep(5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        int globalTotalMessagesSent = 0;
        int globalTotalMessagesReceived = 0;
        int GlobalSumSent = 0;
        int GlobalSumReceived = 0;
        for (Node node : threadPoolOfNodes) {
            System.out.println("Node " + node.getNodeID() + " statistics:");

            System.out.println("Total Sent: " + node.reportTotalSent());
            globalTotalMessagesSent += node.reportTotalSent();

            System.out.println("Total Received: " + node.reportTotalReceived());
            globalTotalMessagesReceived += node.reportTotalReceived();

            System.out.println("Sum Sent: " + node.reportSumSent());
            GlobalSumSent += node.reportSumSent();

            System.out.println("Sum Received: " + node.reportSumReceived());
            GlobalSumReceived += node.reportSumReceived();
        }

        System.out.println("Total Messages Sent -> " + globalTotalMessagesSent);
        System.out.println("Total Messages Received -> " + globalTotalMessagesReceived);
        System.out.println("Global Sum Sent -> " + GlobalSumSent);
        System.out.println("Global Sum Received -> " + GlobalSumReceived);
        System.exit(0);
    }

    public boolean allNodesDone() {
        System.out.println(this.threadPoolOfNodes.length);

        for (int i = 0; i < this.threadPoolOfNodes.length; i++) {
            Node node = this.threadPoolOfNodes[i];
        }

        for (Node node : this.threadPoolOfNodes) {
            if (!node.checkDone()) {
                return false;
            }
        }
        return true;
    }
}
