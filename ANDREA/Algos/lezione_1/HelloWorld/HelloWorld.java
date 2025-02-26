/* 
    per eseguire: 
    javac HelloWorld.java
    java HelloWorld
*/

/**
 * OOP version of the famous <code>Hello, World!</code> code.
 * @author Andrew
 */
public class HelloWorld{
    // final -> constant per variabili; rende impossibile override per metodi
    private final String msg;
    private static final String msgStd = "Daje Roma!";

    /**
     * Stores the <code>msg</code> string parameter
     * @param msg Message to be stored
     */
    public HelloWorld (String msg) {
        this.msg = msg;
    }

    /**
     * stores inside the <code>msg</code> internal variabile the default string <i>Hello, World!</i> 
     */
    public HelloWorld (){
        this.msg = "Hello, World!";
    }

    // static -> condiviso tra tutte le istanze. Posso usare solo variabili static
    /**
     * prints out the Standard message
     */
    public static void printStd(){
        System.out.println(msgStd);
    }
    
    /**
     * Prints out the content of the <code>msg</code> internal variable.
     */
    public void print(){
        System.out.println(msg);
    }

    /**
     * Main method of the class. Prints "Hello, world..." and "Daje Roma!"
     * @param args Command line parameters
     */
    public static void main(String args[]){
        HelloWorld hw = new HelloWorld("Hello, world...");
        hw.print();
        hw.printStd();
    }
}