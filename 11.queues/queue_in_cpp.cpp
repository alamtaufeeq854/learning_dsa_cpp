// Queue In C++
#include <iostream>
using namespace std;

class Queue
{

private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }

    void enqueue(int x);

    int dequeue();

    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue is full" << endl;

    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;

    if (front == rear)
        cout << "Queue is empty" << endl;

    else
    {
        x = Q[front + 1];
        front++;
    }

    return x;
}

void Queue::display()
{
    if (front == rear)
        cout << "Queue is empty" << endl;

    else
    {
        for (int i = front + 1; i <= rear; i++)
            cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(5);

    q.enqueue(2);
    q.enqueue(8);
    q.enqueue(7);

    q.display();

    cout << "Deleted Element: " << q.dequeue() << endl;

    q.display();

    return 0;
}
