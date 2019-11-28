#include "Student.h"
//                advisor id  name    GPA       grade     major
Student::Student(int a, string n, float g, string l, string m)
{
    advisor = a;
    name = n;
    gpa = g;
    grade = l;
    major = m;
}
Student::Student(int a, string n, string l, string m)
{
    Student(a, n, 4.0f, l, m);
}
Student::Student(string n, string l, string m)
{
    Student(1001, n, l, m);
}
Student::Student(string n, string m)
{
    Student(n, "freshman", m);
}
Student::Student(string n)
{
    Student(n, "undeclared");
}
