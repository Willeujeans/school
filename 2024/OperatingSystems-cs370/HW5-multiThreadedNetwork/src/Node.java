package src;

import java.util.Random;
import java.util.concurrent.atomic.AtomicLong;

public class Node extends Thread {
    private String nodeid;
    private Random rng;
    private volatile boolean done;
    private Long qtyMessagesToSend;
    private Node[] neighbors;
    private Producer[] producers;
    private Consumer[] consumers;

    public MessageBuffer messageBuffer;

    private AtomicLong totalMessagesSent;
    private AtomicLong totalMessagesReceived;
    private AtomicLong sumOfMessagesSent;
    private AtomicLong sumOfMessagesReceived;

    public Node(String ID, Long seed, Long messagesToSend, int K, int bufferSize) {
        this.nodeid = ID;
        this.rng = new Random(seed + Long.parseLong(ID));
        this.done = false;
        this.neighbors = new Node[K];
        this.messageBuffer = new MessageBuffer(bufferSize);

        this.totalMessagesSent = new AtomicLong(0);
        this.totalMessagesReceived = new AtomicLong(0);

        this.sumOfMessagesSent = new AtomicLong(0);
        this.sumOfMessagesReceived = new AtomicLong(0);

        this.qtyMessagesToSend = messagesToSend;
        this.producers = new Producer[K];
        this.consumers = new Consumer[K];
        for (int i = 0; i < K; i++) {
            this.producers[i] = new Producer(this, this.qtyMessagesToSend / K);
            this.consumers[i] = new Consumer(this);
        }
        // each producer will create (messagesToSend)/Number of Nodes * K
    }

    public String getNodeID() {
        return this.nodeid;
    }

    public void setNeighbors(Node[] neighbors) {
        this.neighbors = neighbors;
    }

    public Long generateMessage() {
        return Math.abs(rng.nextLong() % 1024);
    }

    public Node selectDestination(int messageValue) {
        return neighbors[messageValue % neighbors.length];
    }

    public void updateSentMessages(Message message) {
        sumOfMessagesSent.addAndGet(message.messageValue);
        totalMessagesSent.incrementAndGet();
    }

    public void updateReceivedMessages(Message message) {
        sumOfMessagesReceived.addAndGet(message.messageValue);
        totalMessagesReceived.incrementAndGet();
    }

    public Long reportTotalSent() {
        return this.totalMessagesSent.get();
    }

    public Long reportTotalReceived() {
        return this.totalMessagesReceived.get();
    }

    public Long reportSumSent() {
        return this.sumOfMessagesSent.get();
    }

    public Long reportSumReceived() {
        return this.sumOfMessagesReceived.get();
    }

    public boolean checkDone() {
        System.out.println(this.getNodeID() + ": " + this.totalMessagesSent.get() + ">=" + this.qtyMessagesToSend);
        this.done = this.totalMessagesSent.get() >= this.qtyMessagesToSend;
        return this.done;
    }

    @Override
    public void run() {
        for (int i = 0; i < this.producers.length; i++) {
            this.producers[i].start();
            this.consumers[i].start();
        }
        while (!this.done) {
            checkDone();
        }
    }

    public MessageBuffer getMessageBuffer() {
        return this.messageBuffer;
    }
}
