package src;

import java.util.Random;

public class VirtualNetworkSimulation {

    private void run() {}

    public static void main(String[] args) {

        long seed = Long.parseLong(args[0]);
        int N = Integer.parseInt(args[1]);
        int K = Integer.parseInt(args[2]);
        int B = Integer.parseInt(args[3]);

        try {
            VirtualNetworkSimulation vns = new VirtualNetworkSimulation();
            vns.run();
        } catch (Exception e) { e.printStackTrace(); }
    }
}
