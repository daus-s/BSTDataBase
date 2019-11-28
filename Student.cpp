#include "Student.h"
//                advisor id  name    GPA       grade     major
Student::Student(int a, string n, float g, string l, string m)
{
    advisor = a;
    name = n;
    gpa = g;
    grade = l;
    major = m;
    id = 02424;/*eventually students get 10000-99999, and faculty 0-9999 based on list with all remaining*/
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

short genID()
{
    return 69420;
}
