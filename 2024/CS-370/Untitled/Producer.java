package src;

public class Producer extends Thread {
    private Node src;
    private Long numberOfMessages;

    public Producer(Node src, Long numberOfMessages) {
        this.src = src;
        this.numberOfMessages = numberOfMessages;
    }

    private Message produceMessage() {
        String sourceID = src.getNodeID();
        Long randomMessageValue = this.src.generateMessage();
        int randomMessageValueInt = randomMessageValue.intValue();
        String destinationID = this.src.selectDestination(randomMessageValueInt).getNodeID(); 
        return new Message(sourceID, destinationID, randomMessageValue);
    }

    private Message sendMessage(Node node, Message message) {
        try {
            this.src.updateSentMessages(node.messageBuffer.emplaceMessage(message));
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        return message;
    }

    private void logOutput(Message message) {
        System.out.println("Node " + src.getNodeID() + ": " + message.messageValue + " sent to Node " + message.destinationID);
    }

    @Override
    public void run() {
        for (long i = 0; i < this.numberOfMessages; i++) {
            System.out.println("🍲:" + src.getNodeID());
            Message sentMessage = sendMessage(this.src, produceMessage());
            logOutput(sentMessage);
        }
    }
}
