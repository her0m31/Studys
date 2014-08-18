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
        System.out.println( "�����ѡ����饹:Person" );
        System.out.println( "������ɽ�����饹" );
    }

    public void methods() {
        System.out.println( "boolean isMylab( String l ) ��ʬ�ν�°���漼���ɤ����θ���" );
        System.out.println( "String selfIntroduction() ���ʾҲ���֤�" );
        System.out.println( "void account() �����ֹ椫��桼����������Ȥ�������֤�" );
    }   

    public void fields() {
        System.out.println( "String lab: ��°���漼���Ǽ (" + lab + ")" );
        System.out.println( "String num: �����ֹ���Ǽ (" + num + ")" );
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