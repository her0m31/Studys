//Person.java

public class Person {
    String name;
    int age;

    public Person(String name, int age) {
        this.name = name;
        this.age  = age;
    }
    
    public Person() {
        this("", 0);
    }

    public String selfIntroduction() {
        return ("Hi, my name is " + name + ". I am " + age + " years old." );
    }

    public static void main(String [] args) {
        Person p1 = new Person("Taro", 20);
        System.out.println(p1.selfIntroduction() );
    }
}