//Output.java
import java.io.*;

public class Output {
    static Cylinder mycylinder;
    static Cylinder [][] cylArray;
    
    public static void printresult(float r, float h, float area, float volume) {
        System.out.println("Cylinder: r= "+ r +" h= "+ h +" area= "+ area +" volume= "+ volume);
    }
    
    public static void printfile(Cylinder [][] cylArray) {
        try {
            FileWriter f      = new FileWriter("result");
            BufferedWriter bw = new BufferedWriter(f);
            PrintWriter pw    = new PrintWriter(bw);
            
            pw.println("   h=  1  2  3  4  5  6");
            pw.println("r= 1"+ cylArray[0][0].area()+ " " + cylArray[0][1].area()+ " " + cylArray[0][2].area()+ " " + cylArray[0][3].area()+ " " + cylArray[0][4].area()+ " " + cylArray[0][5].area());
            pw.println("r= 2"+ cylArray[1][0].area()+ " " + cylArray[1][1].area()+ " " + cylArray[1][2].area()+ " " + cylArray[1][3].area()+ " " + cylArray[1][4].area()+ " " + cylArray[1][5].area());
            pw.println("r= 3"+ cylArray[2][0].area()+ " " + cylArray[2][1].area()+ "  " + cylArray[2][2].area()+ " " + cylArray[2][3].area()+ " " + cylArray[2][4].area()+ " " + cylArray[2][5].area());
            pw.println("r= 4"+ cylArray[3][0].area()+ " " + cylArray[3][1].area()+ " " + cylArray[3][2].area()+ " " + cylArray[3][3].area()+ " " + cylArray[3][4].area()+ " " + cylArray[3][5].area());
            pw.println("r= 5"+ cylArray[4][0].area()+ " " + cylArray[4][1].area()+ "  " + cylArray[4][2].area()+ " " + cylArray[4][3].area()+ " " + cylArray[4][4].area()+ " " + cylArray[4][5].area());
            pw.println("r= 6"+ cylArray[5][0].area()+ "  " + cylArray[5][1].area()+ "  " + cylArray[5][2].area()+ " " + cylArray[5][3].area()+ " " + cylArray[5][4].area()+ " " + cylArray[5][5].area());
            pw.flush();
            pw.close();
        }
        catch(Exception e) {
            System.out.println(e);
        }
    }
    
    public static void main(String [] args) {
        float r = 10;
        float h = 20;
        Cylinder mycylinder    = new Cylinder( r, h );
        Cylinder [][] cylArray = new Cylinder[6][6];
        printresult( r, h, mycylinder.area(), mycylinder.volume() );
    
        for(int i = 0; i < 6; i++) {
            for(int k = 0; k < 6; k++) {
                cylArray[i][k] = new Cylinder(i+1, k+1);
            }
        }
        printfile( cylArray );
    }
}