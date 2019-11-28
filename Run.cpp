#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    openFiles();//?
    parseCommand();
    saveToFile();
}

void parseCommand()
{
    string input;
    int id1;
    ind id2;
    GenericStack stack = new GenericStack(5);
    char** commands;
    while (true)
    {

        cout << "enter a command: ";
        cin >> input;
        commands = split(input, ' ');
        //print commands
        if (input == "print students")
            cout << students->print(students->head) << endl;
        if (input == "print faculty")
            cout << faculty->print(faculty->head) << endl;

        //search commands (4)
        if (commands[0] == "find")
        {
            if (commands[1] == "student")
            {
                if (students->search(atoi(commands[2]))!=NULL)
                    cout << students->search(stoi(commands[2]))->print << endl;
            }
            else if (commands[1]=="faculty")
            {
                  if (students->search(atoi(commands[2]))!=NULL)
                      cout << faculty->search(stoi(commands[2]))->print() << endl;
            }
            // else
            //     input = "-----------------------------------";
            //     commands = split(input, ' ');
        }
        if (commands[0] == "get") //get student advisor <id>
        {
            if (commands[1] == "student")
            {
                if (commands[2]=="advisor") //this check may be redundant but i wanted to make it more robust
                {
                    if (students->search(stoi(commands[3]))!=NULL)
                    {
                        int adv = students->search(stoi(commands[3]))->advisor;
                        cout << faculty->search(adv)->print() << endl;
                    }
                }
            }
            if (commands[1]=="advisor") //get advisor students
            {
                if (commands[2]=="students")
                {
                    if (faculty->search(stoi(commands[3]))!=NULL)
                    {
                        int* list = faculty->search(stoi(commands[3]))->list;

                        for (int i = 0; i <sizeof(list) / sizeof(list[0]); ++)
                        {
                            if (students->search(list[i])!=NULL);
                            {
                                cout << faculty->search(i)->print() << endl;
                            }
                        }
                    }
                }
            }
        }
        //end search commands, the following commands change DB so will be logged in stack
        if (commands[0]=="add")
        {
            if (command[1]=="student")
            {
                Student s;
                if (sizeof(commands)/sizeof(commands[0])==6)
                {
                    s = new Student((short)(atoi(commands[2])),commands[4],(float)(atof(commands[5])),commands[6],commands[7]);
                }
                else if (sizeof(commands)/sizeof(commands[0])==5)
                {
                    s = new Student(commands[2], commands[3], commands[4], (short)atoi(commands[5]);
                }
                else if (sizeof(commands)/sizeof(commands[0])==4)
                {
                    s = new Student(commands[2], commands[3], commands[4]);
                }
                else if (sizeof(commands)/sizeof(commands[0])==3)
                {
                    s = new Student(commands[2], commands[3]);
                }
                else if (sizeof(commands)/sizeof(commands[0])==2)
                {
                    s = new Student(commands[2]);
                }
                stack.push(new Command("insert_s", s));
                students->insert(s);
            }
            if (command[1]=="faculty")
            {                           //name, code generates id, then all student ids
                Advisor a = new Advisor(commands[2], commands[3]);
                for (int i = 4; i < sizeof(commands)/sizeof(commands[0]);++i)
                {
                    if (students->search(atoi(commands[i]))!=NULL)
                        a.add(i);
                    else
                        cout << "error adding student " << commands[i] << ", student does not exist";
                }
                stack.push(new Command("insert_f", a));
            }
        }
        //delete commands
        if (commands[0]=="delete")
        {
            if (command[1]=="student")
            {
                //delete from advisor, then delete
                Student s1 = students->search(atoi(commands[2]));
                if (s1!=NULL)
                {
                    if (faculty->search(s1->advisor)!=NULL)
                    {
                        faculty->search(s1->advisor)->list->remove(s1->id);
                    }
                }
                students->remove(s1->id);//in student tree remove(int)
                stack.push(new Command("delete_s",s1));
            }
            if (command[1]=="faculty")
            {
                Advisor a1 = faculty->search(atoi(commands[2]));
                if (a1!=NULL)
                {
                    for (int i = 0; i < sizeof(commands)/sizeof(commands[0]);++i)
                    {
                        if (students->search(a1->list[i])!=NULL)
                            students->search(a1->list[i]) == 1001; //default
                    }
                }
                stack.push(new Command("delete_f",a1,a1->list));
            }
        }
        if (commands[0]=="change")
        {
            if (commands[1]=="advisor")
            {
                if (students->search(atoi(commands[2]))!=NULL)
                {
                    if (faculty(students->search(atoi(commands[2]))->advisor!=NULL))
                    {
                        short prev = faculty(students->search(atoi(commands[2]))->advisor->id;
                        students->search(atoi(commands[2]))->advisor = commands[3];
                        stack.push(new Command("change", students->search(atoi(commands[2])->data, prev));
                    }
                }
            }
        }
        if (commands[0]=="remove")
        {
            if (commands[1]=="advisee")
            {
                if (faculty->search(atoi(commands[2]))!=NULL)
                {
                    if (students->search(atoi(commands[3]))!=NULL)
                    {
                        short advisee = atoi(commands[3];)
                        students->search(atoi(commands[3]->advisor)) = 1001;
                        faculty->search(atoi(commands[2]))->list->remove(commands[3]);
                        stack.push(new Command("remove", students->search(atoi(commands[2])->data, prev)));
                    }
                }
            }
        }
        if (command[0]==undo)
        {
            Command* undo = stack.pop();
            if (undo->type=="delete_s")
                students->insert(undo->person);
            else
            if (undo->type=="delete_f")
            {
                faculty->insert(undo->person);
                //loop through to give advisor back to students
                for (int i = 0; i < sizeof(undo->list)/sizeof(undo->list[0]); ++i)
                    students->search(undo->list[i])->advisor = undo->person->id;
            }
            else
            if (undo->type=="insert_s")
            {
                faculty->search(students->search(undo->person->id)->advisor)->list->remove(undo->person->id);
                remove(undo->person);
            }
            if (undo->type=="insert_f")
            {
                faculty->remove(undo->person);
                for (int i = 0; i < sizeof(undo->list)/sizeof(undo->list[0]); ++i)
                  students->search(undo->list[i])->advisor = 1001;
            }
            if (undo->type=="change")
            {
                students->search(undo->person->id)->advisor = undo->list[0];
                faculty->search(undo->list[0]).add(undo->person);
            }
            if (undo->type=="remove")
            {
                students->search(list[0])->advisor = undo->person->id;
                faculty->search(undo->person-id).add(undo->search(list[0])->data);
            }
        }

        if (input==exit)
            return;
    }

    //https://thispointer.com/how-to-split-a-string-in-c/ -reference: i really couldnt find a good way to split a string
    vector<string> split(string input, char break)
    {
        stringstream ss(input);
        string index;
        vector<string> list;
        while (getline(ss, index, break))
        {
           list.push_back(item);
        }
        return list;
    }
}
