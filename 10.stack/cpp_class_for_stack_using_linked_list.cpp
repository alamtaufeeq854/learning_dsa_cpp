// C++ Class For Stack Using Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x)
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

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Element Deleted: " << st.pop() << endl;

    st.display();

    return 0;
}