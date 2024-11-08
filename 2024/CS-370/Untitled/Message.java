package src;

public class Message{
    public String sourceID;
    public String destinationID;
    public Long messageValue;

    public Message(String sourceID, String destinationID, Long messageValue){
        this.sourceID = sourceID;
        this.destinationID = destinationID;
        this.messageValue = messageValue;
    }
}
