//ArraySample.java

class ArraySample {
    public static void main(String[] args) {
        int [] ia = new int[4];
        String [] sa = new String[2];
        
        ia[0] = 5;
        ia[2] = 4;
        ia[1] = 34;
        ia[3] = ia[1] + ia[2] + ia[0];
        sa[0] = "apple";
        sa[1] = sa[0] + " juice";
        
        System.out.println( ia[3] );
        System.out.println( sa[1] );
    }
}