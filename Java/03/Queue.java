//Queue.java

public class Queue {
    private int count;
    private int capacity;
    private int capacityIncrement;
    String [] itemList;
    
    public Queue() {
        count    = 0;
        capacity = 5;
        capacityIncrement = 2;
        itemList = new String[capacity];
    }
    
    public Queue(String [] list) {
        count = list.length;
        capacity = list.length;
        capacityIncrement = 5;
        itemList = list;
    }
    
    public void push (String obj) {
        if(count == capacity) {
            capacity += capacityIncrement;
            String [] tempList =new String[capacity];
            for (int i = 0; i < count; i++) {
                tempList[i] = itemList[i];
            }
            itemList = tempList;
        }
        
        itemList[count] = obj;
        count++;
    }

    public String shift() {
               
        if (count == 0) {
            return null;
        }
        else {
            String temps = itemList[0];
            int y = 0;
            for(int i = 1; i < count; i++) {
                itemList[y] = itemList[i];
                y++;
            }
            count--;
            return temps;
        }
    }
    
    public void printItems() {
        for(int i = 0; i < count; i++) {
            System.out.print(itemList[i] + ",");
        }
        System.out.println(" ");
    }
}