//QueueUsage.java

public class QueueUsage implements Usage {
    private int count;
    private int capacity;
    private int capacityIncrement;
    String [] itemList;
    
    public QueueUsage() {
        count    = 0;
        capacity = 5;
        capacityIncrement = 2;
        itemList = new String[capacity];
    }
    
    public QueueUsage(String [] list) {
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

    
    public void usage() {
        System.out.println( "キューを行うクラス" );
    }

    public void methods() {
        System.out.println( "void push(String obj) キューに値を入れる" );
        System.out.println( "String shift() プッシュされたら一個前にずらす。容量を越えたら先頭の値を返す" );
        System.out.println( "void printItems() キューの内容を表示" );
    }   

    public void fields() {
        System.out.println( "private int count: キューのアイテム数" );
        System.out.println( "private int capacity: キューの配列の数量" );
        System.out.println( "private int capacityIncrement: 配列の数量を増やす" );
        System.out.println( "String [] itemList: キューの配列" );

    }   
}