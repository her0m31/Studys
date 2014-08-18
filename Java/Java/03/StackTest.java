//StackTest.java

public class StackTest {
    public static void main (String [] args) {
        String [] items = {"Kenji", "Nobu"};
        Stack mystack = new Stack(items);
        System.out.println("Initial data :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        mystack.printItems();
        mystack.push("Taro");
        System.out.println("Data after push Taro :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        String popObject1 = mystack.pop();
        System.out.println("Data after pop object " + popObject1 + " :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
        String popObject2 = mystack.pop();
        System.out.println("Data after pop object " + popObject2 + " :");
        mystack.printItems();
        System.out.println(" ");
        System.out.println("------------");
    }
}