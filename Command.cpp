#include "command.h"
#include "Person.h"

//see header file for documentation
Command::Command(string t, Person p)
{
    type = t;
    person = p;
}
Command::Command(string t, Person p, short* ids)
{
    type = t;
    person = p;
    list = ids;
}
Command::Command(string t, Person p, short id)
{
    type = t;
    person = p;
    list = new short[1];
    list[0] = id;
}
