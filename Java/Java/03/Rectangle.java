//Rectangle.java

public class Rectangle {
    protected double width, height;
    public Rectangle(double w, double h) {
        width  = w;
        height = h;
    }

    public Rectangle() {
        width  = 3;
        height = 3;
    }

    double area() {
        return width * height;
    }

    public double circumference() {
        return 2 * (width + height);
    }

    public static void main(String [] args) {
        Rectangle r1 = new Rectangle(10.0, 5.0);
        System.out.println("Rectangle 1:" );
        System.out.println("width is " + r1.width );
        System.out.println("height is " + r1.height );
        System.out.println("area is " + r1.area());
        System.out.println("circumference is " + r1.circumference() );
        System.out.println("---------------------------" );
        System.out.println("Rectangle 2:" );
        Rectangle r2 = new Rectangle();
        System.out.println("width is " + r2.width );
        System.out.println("height is " + r2.height );
        System.out.println("area is " + r2.area() );
        System.out.println("circumference is " + r2.circumference() );
    }
}