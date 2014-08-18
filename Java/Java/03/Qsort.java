//Qsort.java

public class Qsort {
    
    public static void quickSort(int[] arr, int left, int right){
        if ( left <= right ) {
            int p = arr[ (left + right) / 2 ];
            int l = left;
            int r = right;
            
            while( l <= r ) {
                while( arr[l] < p )
                    l++; 
                
                while( arr[r] > p )
                    r--;
                
                if ( l <= r ) {
                    int tmp = arr[l];
                    arr[l]  = arr[r];
                    arr[r]  = tmp;
                    l++;
                    r--;
                }
            }
            
            quickSort(arr, left,     r);
            quickSort(arr,    l, right);
        }
    }
    
    public static void arrayPrintln(int[] arr){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }
    
    public static void main(String[] args){
        int[] arr = {1, 6, 15, 12, 7, 9, 23, 2, 10, 4, 20};
        
        System.out.print("Before: ");
        arrayPrintln(arr);
        
        quickSort(arr, 0, arr.length-1);
        
        System.out.print("After: ");
        arrayPrintln(arr);
    }
}