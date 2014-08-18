//Circle.java

public class Circle {
    protected double x, y, r;

    public Circle(double a, double b, double c) {
        x = a;
        y = b;
        r = c;
    }

    public Circle() {
        x = 0.0;
        y = 0.0;
        r = 1.0;
    }

    public double circumference() {
        return 3.1415 * r * 2;
    }

    public double area() {
        return 3.1415 * r * r;
    }

    public void transfer(double a, double b) {
        x = x + a;
        y = y + b;
    }

    public static void main(String [] args) {
        Circle r1 = new Circle(10.0, 5.0, 4.0);
        System.out.println("Circle 1:" );
        System.out.println("Circumference is " + r1.circumference() );
        System.out.println("Area is " + r1.area());
        System.out.println("---------------------------" );
        System.out.println("Transfer:" );
        r1.transfer(7.0, 10.0);
        System.out.println("After Transfer (x , y) (" + r1.x + " , " + r1.y + " )" );
    }
}