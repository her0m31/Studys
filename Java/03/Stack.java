//Stack.java

public class Stack {
    private int count;
    private int capacity;
    private int capacityIncrement;
    String [] itemList;
    
    public Stack() {
        count    = 0;
        capacity = 5;
        capacityIncrement = 2;
        itemList = new String[capacity];
    }
    
    public Stack(String [] list) {
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
    
    public String pop() {
        if (count == 0) {
            return null;
        }
        else {
            count--;
            return itemList[count];
        }
    }
    
    public void printItems() {
        for(int i = 0; i < count; i++) {
            System.out.print(itemList[i] + ",");
        }
        System.out.println(" ");
    }
}