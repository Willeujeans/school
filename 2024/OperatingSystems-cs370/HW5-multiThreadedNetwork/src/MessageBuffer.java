package src;

public class MessageBuffer {
    private Message[] internalMessageBuffer;
    private int bufferCapacity;
    private int head;
    private int tail;

    public MessageBuffer(int size) {
        this.bufferCapacity = size;
        this.internalMessageBuffer = new Message[size];
        this.head = 0;
        this.tail = 0;
    }

    public Message emplaceMessage(Message message) {
        synchronized (this.internalMessageBuffer) {
            while (this.bufferCapacity == 0) {
                try {
                    this.internalMessageBuffer.wait();
                } catch (Exception e) {
                }
            }
            this.internalMessageBuffer[tail] = message;
            tail = (tail + 1) % this.internalMessageBuffer.length;
            this.bufferCapacity--;
            this.internalMessageBuffer.notifyAll();
            return message;
        }
    }

    public Message pollMessage() {
        synchronized (this.internalMessageBuffer) {
            while (this.bufferCapacity == this.internalMessageBuffer.length) {
                try {
                    this.internalMessageBuffer.wait();
                } catch (Exception e) {
                }
            }
            Message message = this.internalMessageBuffer[head];
            this.internalMessageBuffer[head] = null;
            head = (head + 1) % this.internalMessageBuffer.length;
            this.bufferCapacity++;
            this.internalMessageBuffer.notifyAll();
            return message;
        }
    }

    public int getBufferCapacity() {
        return this.bufferCapacity;
    }
}
