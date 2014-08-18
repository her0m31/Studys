//StudentUsage.java
//Person subclass

public class StudentUsage extends Person implements Usage {
    String lab;
    String num;

    public StudentUsage( String name, int age, String lab, String num ) {
        super( name, age );
        this.lab = lab;
        this.num = num;
    }

    public StudentUsage() {
        super();
        this.lab = "";
        this.num = "";
    }

    public boolean isMylab( String l ) {
        return lab.equals( l );
    }

    public String selfIntroduction() {
        String si = super.selfIntroduction();
        return ( si + "I'm a member of the " + lab + " lab. " + "\nMy student ID is " + num + "." );
    }

    public String account() {
        int yea = 'a' + ( Integer.parseInt( num.substring( 3, 7 ) ) % 26 );
        
        return ( "g031" + (char)yea + num.substring( 7, 10 ) );
    }
    
    public void usage() {
        System.out.println( "スーパークラス:Person" );
        System.out.println( "学生を表すクラス" );
    }

    public void methods() {
        System.out.println( "boolean isMylab( String l ) 自分の所属研究室かどうかの検査" );
        System.out.println( "String selfIntroduction() 自己紹介を返す" );
        System.out.println( "void account() 学生番号からユーザアカウントを作成し返す" );
    }   

    public void fields() {
        System.out.println( "String lab: 所属研究室を格納 (" + lab + ")" );
        System.out.println( "String num: 学籍番号を格納 (" + num + ")" );
    }   
    
    public static void main(String [] args) {       
        StudentUsage p1 = new StudentUsage( "Fujita", 20, "Dais", "0312010142" );
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