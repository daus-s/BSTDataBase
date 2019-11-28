class Person
{
    public:
        short id;
        string name;

        string print();
        Person();
        Person(string n);
        short genId();

        Person operator< (Person p)
        {
            return id < p.id;
        }

        Person operator> (Person p)
        {
            return id < p.id;
        }

        Person operator== (Person p)
        {
            return id = p.id;
        }
}
