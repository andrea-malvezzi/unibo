public class Pair {
    int x;
    int y;
    
    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object obj){
        if (obj == null || !(obj instanceof Pair))
            return false;

        // I need to cast
        Pair p = (Pair)obj;
        return this.x == p.x && this.y == p.y;
    }
}