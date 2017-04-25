/* Maria Sanchez
 * 3/29/17
 *
 * The purpose of this program is to validate that a stack and a queue 
 * are identical. Identical meaning: having the same number of elements, symbols, 
 * and their elements and symbols at corresponding positions are the same. Additionally,
 * the program outputs whether the elements have matching group symbols.
 *
 */


#include <iostream>
#include <sstream>
#include <string>


using namespace std;



//stack Template
template <typename T>
class Stack
{
private:
    T* stackList;
    int stackSize;
    T front;
public:
    Stack();
    T getFront();
    void setArray(int);
    int getSize();
    bool isEmpty();
    void makeEmpty();
    void pop();
    void push(T);
};
//stack methods
//constructor
template <typename T>
Stack<T>::Stack()
{
    stackSize = 0;
    
}
template <typename T>
void Stack<T>::setArray(int size)
{
    //initialize array dynamically
    stackList = (char *)(malloc(sizeof(char)*size));
}
//get top element of stack
template <typename T>
T Stack<T>::getFront()
{
    return stackList[stackSize -1];
}
//get the number of elements in the stack
template <typename T>
int Stack<T>::getSize()
{
    return stackSize;
}
//check if the stack is empty
template <typename T>
bool Stack<T>::isEmpty()
{
    if( stackSize==0 )
        return true; //no elements in the stack
    else
        return false;
}
//empty the stack for again use
template <typename T>
void Stack<T>::makeEmpty()
{
    if( stackSize!=0 ) //only empty if there are elements
    {
        free(stackList); //clear the stack
        stackSize = 0; //reset size to 0
    }
}
//delete top element form the stack
template <typename T>
void Stack<T>::pop()
{
    stackSize--; //decrease size by one
    if(stackSize>0)
        front = stackList[stackSize-1]; //change the front element
    else
        front = 0;

}
//insert element in the stack
template <typename T>
void Stack<T>::push(T val)
{
    // T * stackList = (T *) realloc(stackList, stackSize+1);
    stackList[stackSize]=val; //add element to the stack
    stackSize++; //increase the size by 1
    front = val; //change the front to reflect the increase
}


//queue Template
template <typename T> //enables a queue of any data type
class Queue //implement a queue that the user adds element to
{
private:
    T* queueList;
    int queueSize;
    int frontIndex, backIndex;
    T front;
    T rear;
public:
    Queue(); //constructor
    void dequeue();
    void setArray(int);
    T getRear();
    int getSize();
    void enqueue(T);
    bool isEmpty();
    void makeEmpty();
};
//queue methods
//constructor
template <typename T>
Queue<T>::Queue()
{
    
    //set everything to 0
    queueSize = 0;
    frontIndex = 0;
    backIndex = 0;
}
template <typename T>
void Queue<T>::setArray(int size)
{
    //initialize array dynamically
    queueList = (char *)(malloc(sizeof(char)*size));
}
//get rear element of queue
template <typename T>
T Queue<T>::getRear()
{
    return queueList[backIndex];
}
//get the number of elements in the queue
template <typename T>
int Queue<T>::getSize()
{
    return queueSize;
}
//check if the queue is empty
template <typename T>
bool Queue<T>::isEmpty()
{
    if( queueSize==0 ) //check for elements
        return true;
    else
        return false;
}
//empty the queue for again use
template <typename T>
void Queue<T>::makeEmpty()
{
    if( queueSize!=0 ) //check if the queue is already empty
    {
        free(queueList);
        queueSize = 0;
        frontIndex = 0;
        backIndex = 0;
    }
    
    return;
}
//delete back element form the queue
template <typename T>
void Queue<T>::dequeue()
{
    if( queueSize!=0 ) //check if there are elements present
    {
        queueSize--;
        backIndex++;
        rear = queueList[backIndex];
    }
    
    return;
}

//insert element in the queue at the front end
template <typename T>
void Queue<T>::enqueue(T val)
{
    // T * queueList = (T *) realloc(queueList, queueSize+1);
    queueList[frontIndex] = val; //add element to queue at the front
    queueSize++;
    frontIndex++;
    if( queueSize == 1 )
    {
        front = val;
        rear = val;
    }
}


//creating elements
Stack<char> stack;
Queue<char> queue;

//helper classes
void insertInQueue(string s)
{
    int l = s.size();
    queue.setArray(l);
    for(int i=0;i<l;i++){
        
        queue.enqueue(s[i]);
    }
    
}
void insertInStack(string s)
{
    int l = s.size();
    stack.setArray(l);
    for(int i=0;i<l;i++)
        stack.push(s[i]);
    
}
bool checkEqual()
{
    if(stack.getSize()!=queue.getSize())
        return false;
    int size = stack.getSize();
    char stackArray[size], queueArray[size]; //for comparing
    for(int i=0;i<size;i++){
        // cout<<i<<"\t"<<stack.getFront()<<"\t"<<queue.getRear();
        stackArray[size-i-1] =stack.getFront();
        queueArray[i] = queue.getRear();
        //remove items from both lists
        stack.pop();
        queue.dequeue();
    }
    for( int i = 0; i < size; i++ )
    {
        if( stackArray[i] != queueArray[i] )
            return false;
    }
    return true;
}

bool checkMatching(string s)
{
    Stack<char> temp;
    temp.setArray(s.size());

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{' || s[i]=='<')
            temp.push(s[i]);
        else if(s[i]==')' || s[i]==']' || s[i]=='}' || s[i]=='>')
        {
            if(temp.isEmpty())
                return false;
            char t = temp.getFront();
            if(t=='(' && s[i]!=')')
                return false;
            if(t=='{' && s[i]!='}')
                return false;
            if(t=='[' && s[i]!=']')
                return false;
            if(t=='<' && s[i]!='>')
                return false;
            //stack.pop();
        }
        // for(int j=0;j<stk_size;j++)
        // 	cout << stk[j] << " ";
        // cout << "\n";
    }
    if(temp.getSize()>0)
        return false;
    return true;
    
}



int main()
{
    
    // INTRO TO PROGRAM
    cout << " *** Welcome to My stack / Queue Program ***" << endl;
    cout << endl << "The function of this program is to : " << endl;

    cout << endl << "       1-  Validate that a stack and a queue is identical. Stacks / Queues" << endl;
    cout << "        are same if they have the same number of elements, symbols, and their" << endl;
    cout << "        elements and symbols at the corresponding positions are the same" << endl;

    cout << endl << "       2 - The program also outputs whether the elements do have the same" << endl;
    cout << "         matching group symbols" << endl;

    // END PROGRAM INTRO


    while(true)
    {
        stack.makeEmpty();
        queue.makeEmpty();
        char ch;
        string entry;
        cout << endl << endl << endl << "Select from the following menu.\n";
        cout << "1. Enter Stack/Queue Values.\n";
        cout << "9. Terminate the program.\n";
        cin >> entry;
        ch=entry[0];
        if(entry.size()>1|| (ch!='1' && ch!='9'))
        {
            //invalid entry
            cout << "Invalid Option\n";
            continue;
        }
        if(ch=='9'){
            //exit the program
            cout << " *** The Program is terminated. Written by Maria Sanchez ***" << endl;
            break;
        }
        string stks, qus;
        cout<<endl;
        cout << "Enter Stack Values terminated by ;   ";
        getline(cin,stks,';');
        insertInStack(stks);
        cout << endl << "Enter Queue Values terminated by ;   ";
        getline(cin,qus,';');
        insertInQueue(qus);
        if(checkEqual())
            cout << "Stack and Queue are identical\n";
        else
            cout << "Stack and Queue are not identical\n";
        //clear the stack, we need the stack to verify matching group in first stack.
        
        //stack.makeEmpty();
        if(!checkMatching(stks))
            cout << "First Expression does not have matching grouping symbols\n";
        else
            cout << "First Expression has matching grouping symbols\n";
        
        
    }
    return 0;
}
