//Prime2.java

class Prime2 {
    public static void main(String [] args) {
        int i, j;
        boolean isPrime = true;
        int x = 1;
        
        for(i = 2; 0 < i; i++) {
            for(j = 2; j < i - 1; j++) {
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if( isPrime ) {
                if( x == Integer.parseInt(args[0]) )
                    break;
                x++;
            }
            else
                isPrime = true;
        }

        System.out.println(args[0] + "番目の素数: " + i);
    }
}