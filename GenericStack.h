using namespace std;

template <class Generic> class GenericStack
{



    public:
        int index;
        int size;

        Generic* stack;

        //simply returns the top element in the stack there is no change to the program
        Generic peek()
        {
            if (!isEmpty())
                return stack[index];
            else throw "StackEmpty";
        }
        //removes and returns the top elementin the stack
        Generic pop()
        {
            cout << "pop" << endl;
            if (index > 0)
            {
                index--;
                return stack[index];
            }
            else throw "StackEmpty";
        }

        //this puts the index and newest point to the top of the stack
        //this is acting funny
        void push(Generic c)
        {
            if (isFull)
                limit();
            index++;
            stack[index] = c;
        }

        //tells if the array in the stack is full
        bool isFull()
        {
            return size == index + 1;
        }
        //tells if the num of ele in the array is 0 or whether it is empty
        bool isEmpty()
        {
            return index == 0;
        }

        //constructors and destructor
        GenericStack()
        {
            //TODO: question to ask, can i put index = -1 in the header
            index = -1;
            size = 128;
            stack = new Generic[size];
        }

        GenericStack(int s)
        {
            index = -1;
            size = s;
            stack = new Generic[size];
        }

        ~GenericStack()
        {
            delete stack;
        }

        //to_string() mainly for debugging but prints the stack
        string to_string()
        {
            string text = "";
            for (int i = 0; i < index; ++i)
            {
                if (i == 0)
                {
                    text += stack[i];
                }
                else
                {
                    text += ", " + stack[i];
                }
            }
            return text;
        }
        //dubles the size of the stack
        void resize()
        {
            Generic* copy = new Generic[2*size];
            for (int i = 0; i < index; ++i)
            {
                copy[i] = stack[i];
            }
            stack = copy;
            delete copy;
        }
        void limit()
        {
            for (int i = size; i < 1; --i)
            {
                stack[i] = stack[i-1];
            }
            stack[0] = NULL; //fill in first with non data field then update
            index--;
        }
};
