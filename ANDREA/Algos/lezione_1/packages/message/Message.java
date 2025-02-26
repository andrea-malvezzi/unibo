package message;

/**
 * Class able to store and print out a String
 * @author Andrew
 * @version 1.0
 */
public class Message{
    private final String msg;

    /**
     * Stores the default string <i>Hello, world!</i> inside the private constant <code>msg</code>.
     */
    public Message(){
        this.msg = "Hello, world!";
    }

    /**
     * Stores a String inside the private variable <code>msg</code>.
     * @param msg The message that will be stored in the constant.
     */
    public Message(String msg){
        this.msg = msg;
    }

    /**
     * Prints out the content inside the <code>msg</code> constant.
     */
    public void printMsg(){
        System.out.println(msg);
    }
}