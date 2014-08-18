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
        System.out.println( "���塼��Ԥ����饹" );
    }

    public void methods() {
        System.out.println( "void push(String obj) ���塼���ͤ������" );
        System.out.println( "String shift() �ץå��夵�줿�������ˤ��餹�����̤�ۤ�������Ƭ���ͤ��֤�" );
        System.out.println( "void printItems() ���塼�����Ƥ�ɽ��" );
    }   

    public void fields() {
        System.out.println( "private int count: ���塼�Υ����ƥ��" );
        System.out.println( "private int capacity: ���塼������ο���" );
        System.out.println( "private int capacityIncrement: ����ο��̤����䤹" );
        System.out.println( "String [] itemList: ���塼������" );

    }   
}