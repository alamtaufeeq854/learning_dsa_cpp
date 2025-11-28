// Parenthesis Matching
#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    int push(char x);
    int pop();
    void display();
    int isEmpty();
};

int Stack::push(char x)
{
    Node *t = new Node;

    if (t == NULL)
        cout << "Stack Is Full" << endl;

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;

    if (top == NULL)
    {
        cout << "Stack Is Empty" << endl;
        return x;
    }

    else
    {
        Node *t = new Node;
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Stack::display()
{
    if (top == NULL)
        cout << "Stack Is Empty" << endl;

    else
    {
        Node *t = new Node;
        t = top;

        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
}

int Stack::isEmpty()
{
    return top ? 0 : 1;
}

int isBalanced(char *exp)
{
    struct Stack st;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
            st.push(exp[i]);

        else if (exp[i] == ')')
        {
            if (st.isEmpty())
                return false;

            st.pop();
        }
    }
    return st.isEmpty() ? true : false;
}

int main()
{

    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;

    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;

    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;

    return 0;
}