class Command
{
    string type;//this only applies to commands effecting the tree structure
    Person person; //we can generalize this to not be only for student/faculty->all bst undos.
    short* list;

    Command(string t, Person p);
    //for simple insert and delete on singular cases
    Command(string t, Person p, short* ids);
    //used for inserts and deletes where there are pularalities i.e. faculty having lists
    Command(string t, Person p, short id);
    //used for change and remove funcitonalies where the lists remain changed solely indexwise.

    //i dont want empty or incomplete constructors
}
