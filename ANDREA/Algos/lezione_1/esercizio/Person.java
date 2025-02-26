public class Person{
    private final String name;
    private final String surname;
    private int age;
    private Continent continent;
    
    public Person(String name, String surname, int age, Continent continent) {
        this.name       = name;
        this.surname    = surname;
        this.age        = age;
        this.continent  = continent;
    }

    public Person(String name, String surname){
        this.name       = name;
        this.surname    = surname;
        this.age        = -1;
        this.continent  = Continent.UNKNOWN;
    }

    public void SetAge(int age){
        if (age >= 0)
            this.age = age;
    }

    public void SetContinent(Continent continent){
        this.continent = continent;
    }

    public void GetInfo(){
        // print formatted instead of string concatenation
        System.out.printf("My name is %s %s. I am %d years old and I live in %s.%n", this.name, this.surname, this.age, this.continent);
    }

    public static void main(String[] args){
        Person p = new Person("Andrew", "Malvezzi", 19, Continent.EUROPE);
        p.GetInfo();
    }
}