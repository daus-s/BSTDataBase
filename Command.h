class Command
{
    char operation;//this only applies to commands effecting the tree structure
    int key; //we can generalize this to not be only for student/faculty->all bst undos.

    Command(char o, int i);
    //i dont want empty or incomplete constructors
}
