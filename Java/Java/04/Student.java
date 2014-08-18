//Student.java
//Person subclass

public class Student extends Person {
    String lab;
    String num;

    public Student( String name, int age, String lab, String num ) {
        super( name, age );
        this.lab = lab;
        this.num = num;
    }

    public Student() {
        super();
        this.lab = "";
        this.num = "";
    }

    public boolean isMylab( String l ) {
        return lab.equals( l );
    }

    public String selfIntroduction() {
        String si = super.selfIntroduction();
        return ( si + "I'm a member of the " + lab + " lab. " + "My student ID is " + num + "." );
    }

    public String account() {
        int yea = 'a' + ( Integer.parseInt( num.substring( 3, 7 ) ) % 26 );
        
        return ( "g031" + (char)yea + num.substring( 7, 10 ) );
    }
    
    public static void main(String [] args) {       
        Student p1 = new Student( "Fujita", 20, "Dais", "0312010142" );
        System.out.println( p1.selfIntroduction() );
        
        String s = "Dais";
        
        if( p1.isMylab( s ) ) {
            System.out.println(p1.name + "'s lab is " + s + ".");
        } else {
            System.out.println(p1.name + "'s lab is not " + s + ".");
        }

        System.out.println( "My account is " + p1.account() + ".");
    }
}