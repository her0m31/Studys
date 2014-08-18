//FacultyMember.java
//Person subclass

public class FacultyMember extends Person {
    String post;

    public FacultyMember( String name, int age, String post ) {
        super( name, age );
        this.post = post;
    }
    
    public FacultyMember() {
        super();
        this.post = "";
    }

    public boolean isMyPost( String p ) {
        return post.equals( p );
    }

    public String selfIntroduction() {
        String s = super.selfIntroduction();
        return ( s + " My post is " + post + "." );
    }

    public static void main(String [] args) {

        FacultyMember p1 = new FacultyMember( "Kentaro", 40, "Professor" );
        System.out.println( p1.selfIntroduction() );
        
        String s = "Professor";
        
        if( p1.isMyPost( s ) ) {
            System.out.println(p1.name + "'s post is " + s + ".");
        } else {
            System.out.println(p1.name + "'s post is not " + s + ".");
        }
    }
}