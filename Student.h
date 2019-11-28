class Student : public Person
{
    public:
        int advisor;
        ID id;
        string name;
        float gpa;
        string grade;
        string major;

        //most specific, fields to
        Student(int advisor, string name, float gpa, string grade, string major);
        Student(string name, string major, string grade, int advisor);
        Student(string name, string major, string grade);
        Student(string name, string major);
        Student(string name);
        //least specific
}
