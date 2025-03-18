public class Test {
    public static void main(String args[]){
        String s1 = new String("pippo");
        String s2 = new String("pippo");

        Integer x1 = Integer.valueOf(1);
        Integer x2 = Integer.valueOf(1);

        System.out.println("s1 == s2? " + s1.equals(s2));
        System.out.println("x1 == x2? " + x1.equals(x2));
        System.out.println("s1 == x1? " + s1.equals(x1));

        //---------------------------------------------------
        Pair p1 = new Pair(1, 1);
        Pair p2 = new Pair(1, 1);

        System.out.println("p1 == p2? " + p1.equals(p2));
    }
}
