//ExecIncrement.java

public class ExecIncrement implements Runnable {
    Increment inc;
    char mes;
    long sleeptime;

    ExecIncrement( Increment inc, char mes, long sleeptime ) {
        this.inc = inc;
        this.mes = mes;
        this.sleeptime = sleeptime;
    }

    public void run() {
        inc.calc( mes, sleeptime );
    }
}