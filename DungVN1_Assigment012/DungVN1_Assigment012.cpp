#include "CStack.h"
#include <string.h>

using namespace std;

#define MAX_SIZE 100        // Max size of the stack


/************************************
*Function: Push data into stack
*Return  : void
************************************/

void CStack::Push(int x)
{
    if (size >= MAX_SIZE)
    {
        cout << "Stack overflow\n";
    }
    else
        stack[size++] = x;
}


/************************************
*Function: Pop data out of stack
*Return  : The top element of the stack
************************************/

int CStack::Pop()
{
    if (size == 0)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        return stack[--size];
    }

}

/***************************************
*Function: show all of elements of stack
*Return  : void
***************************************/
void CStack::Show()
{
    for (int i = 0; i < size; i++)
    {
        cout << "s[" << i << "] = " << stack[i] << "\n";
    }
}

void main()
{
    CStack stack;
    int top ;
    int num ;
    int opt ;
    while (1)
    {
    cout << "Select option:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Show\n";
    cout << "4. Exit\n";
    cin >> opt;


        switch (opt)
        {

        case 1:
        {
            cout << "Type a number want to push:\n";
            cin >> num;
            stack.Push(num);
            stack.Show();
            break;
        }

        case 2:
        {
            top = stack.Pop();
            cout << "top = " << top << endl;
            stack.Show();
            break;
        }

        case 3:
        {    stack.Show();
        break;
        }

        case 4:
        {
            exit(1);
        }

        default:
        {
            cout << "invalid, please retype an other option:\n";
        }
        }

    }

}