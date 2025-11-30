// More On parenthesis Matching
#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
private:
    char *S;
    int top, Size;

public:
    Stack(int n)
    {
        Size = n;
        top = -1;
        S = new char[Size];
    }

    void push(char ch)
    {
        if (IsFull())
            cout << "Stack Overflow";
        else
            S[++top] = ch;
    }

    char pop()
    {
        if (IsEmpty())
            return -1;
        return S[top--];
    }

    int IsEmpty() { return top == -1; }
    int IsFull() { return top == Size - 1; }
    char StackTop() { return IsEmpty() ? -1 : S[top]; }
};

bool isBalanced(char exp[])
{
    Stack st(strlen(exp));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            st.push(exp[i]);

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (st.IsEmpty())
                return false;

            if ((exp[i] == st.StackTop() + 1) || (exp[i] == st.StackTop() + 2))
                st.pop();
            else
                return false;
        }
    }
    return st.IsEmpty();
}

int main()
{
    char A[100];
    cout << "Enter Expression: ";
    cin >> A;

    cout << (isBalanced(A) ? "Matched" : "Not Matched");
    return 0;
}
