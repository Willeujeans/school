package src;

public class Consumer extends Thread {
    private Node src;

    public Consumer(Node src) {
        this.src = src;
    }

    private Message consumeMessage() {
        return this.src.messageBuffer.pollMessage();
    }

    private void logInput(Message message) {
        if (message != null) {
            System.out.println("Node " + message.destinationID + ": Received " + message.messageValue + " from Node "
                    + message.sourceID + ".");
        }
    }

    @Override
    public void run() {
        while (true) {
            Message consumedMessage = consumeMessage();
            src.updateReceivedMessages(consumedMessage);
            logInput(consumedMessage);
        }
    }
}
