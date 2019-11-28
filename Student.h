class Student : public Person
{
    public:
        short advisor;
        float gpa;
        string grade;
        string major;

        //CONSTRUCTORS
        //most specific, fields to
        Student(short advisor, string name, float gpa, string grade, string major);
        Student(string name, string major, string grade, int advisor);
        Student(string name, string major, string grade);
        Student(string name, string major);
        Student(string name);
        //least specific

        string print();

}
