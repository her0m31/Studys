//Prime.java

class Prime {
    public static void main(String [] args) {
        int [] ia = new int[1001];
        int i, j, x, y;

        x = y = 0;
        for(i = 2; i < ia.length; i++) {
            if( ia[i] == 0 ) {
                x++;
                y += i;
                for( j = i; j < ia.length; j += i) 
                    ia[j] = 1;
            }
        }
        System.out.println("¸Ä¿ô: " + x);
        System.out.println("¹ç·×: " + y);
    }
}