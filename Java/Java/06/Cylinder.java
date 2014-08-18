//Cylinder.java

public class Cylinder {
    private float radius;
    private float height;
    
    public Cylinder() {
        this.radius = 0;
        this.height = 0;
    }
    
    public Cylinder( float r, float h ) {
        this.radius = r;
        this.height = h;
    }
    
    public float area() {
        return ( (radius * radius * (float)Math.PI * 2) 
                 + (radius * 2 * (float)Math.PI * height) );
    }

    public float volume() {
        return (radius * radius * (float)Math.PI * height );
    }
}