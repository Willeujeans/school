package src;

public class Consumer extends Thread {
    private Node src;

    public Consumer(Node src) {
        this.src = src;
    }

    private Message consumeMessage() {
        try {
            return this.src.messageBuffer.pollMessage();
        } catch (InterruptedException ex) {
            return null;
        }
    }

    private void logInput(Message message) {
        if (message != null) {
            System.out.println("Node " + message.destinationID + ": Received " + message.messageValue + " from " + message.sourceID + ".");
        }
    }

    @Override
    public void run() {
        for(int i = 0; i < 50; i++){
            System.out.println("👄: " + src.getNodeID());
            Message consumedMessage = consumeMessage();
            src.updateReceivedMessages(consumedMessage);
            logInput(consumedMessage);
        }
    }
}
