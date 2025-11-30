// Infix to Postfix With Associativity And Parenthesis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (!t)
        return;
    t->data = x;
    t->next = top;
    top = t;
}
char pop()
{
    if (!top)
        return -1;
    struct Node *t = top;
    char x = t->data;
    top = top->next;
    free(t);
    return x;
}

int isOperand(char x)
{
    return !(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')');
}
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}
int isRightAssoc(char x)
{
    return x == '^';
}

char *inToPostfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix = (char *)malloc(strlen(infix) + 5);

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];

        else if (infix[i] == '(')
            push(infix[i++]);

        else if (infix[i] == ')')
        {
            while (top && top->data != '(')
                postfix[j++] = pop();
            pop();
            i++;
        }
        else
        {
            while (top && top->data != '(' &&
                   (pre(infix[i]) < pre(top->data) ||
                    (pre(infix[i]) == pre(top->data) && !isRightAssoc(infix[i]))))
                postfix[j++] = pop();
            push(infix[i++]);
        }
    }

    while (top)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[] = "((a+b)*c)-d^e^f";

    char *postfix = inToPostfix(infix);
    printf("%s", postfix);

    return 0;
}
