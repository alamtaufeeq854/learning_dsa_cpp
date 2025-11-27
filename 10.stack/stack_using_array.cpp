// Stack Using Array
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d", &st->size);

    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");

    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");

    else
        x = st->s[st->top--];

    return x;
}

void display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
        printf("%d\n", st.s[i]);
}

int peek(struct Stack st, int index)
{
    int x = -1;

    if (st.top - index + 1 < 0)
        printf("Invalid Index\n");

    else
        x = st.s[st.top - index + 1];

    return x;
}

void isFull(struct Stack st)
{
    if (st.top != st.size - 1)
        printf("Not Full\n");

    else
        printf("Full\n");
}

void isEmpty(struct Stack st)
{
    if (st.top == -1)
        printf("Empty\n");

    else
        printf("Not Empty\n");
}

int stackTop(struct Stack st)
{
    if (st.top >= 0)
        return st.s[st.top];

    else
        printf("Empty Stack\n");
    return -1;
}

int main()
{
    struct Stack st;

    create(&st);

    push(&st, 8);
    push(&st, 4);
    push(&st, 9);

    display(st);

    printf("At Position 2nd: %d", peek(st, 2));
    pop(&st);
    printf("\nDeleted\n");
    display(st);
}