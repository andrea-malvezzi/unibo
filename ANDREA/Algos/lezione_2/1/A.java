public class A extends B {
    private String msg = "I am the A class";
    
    // if print were not there, it would call the print of the super class (B)
    // B print method is final -> i cannot override
    // public void print() {
    //     // super -> father class
    //     // super.msg -> the msg var in the B class
    //     System.out.println(super.msg);
    //     System.out.println(msg);
    // }
}
