//UsageQueue.java

public class UsageQueue {
    public static void main (String [] args) {
        String [] items = {};
        QueueUsage mystack = new QueueUsage(items);
      
        mystack.usage();
        mystack.methods();
        mystack.fields();
    }
}