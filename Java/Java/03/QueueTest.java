//QueueTest.java

public class QueueTest {
    public static void main (String [] args) {
        String [] items = {};
        Queue mystack = new Queue(items);
        System.out.println("Initial data :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        mystack.push("Komachi");
        System.out.println("Data after push Komachi :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        mystack.push("Yamabiko");
        System.out.println("Data after push Yamabiko :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        mystack.push("Tsubasa");
        System.out.println("Data after push Tsubasa :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        mystack.push("Nasuno");
        System.out.println("Data after push Nasuno :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        String popObject1 = mystack.shift();
        System.out.println("Data after pop object " + popObject1 + " :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        String popObject2 = mystack.shift();
        System.out.println("Data after pop object " + popObject2 + " :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
    }
}