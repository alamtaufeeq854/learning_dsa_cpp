// C++ class for diagonal matrix
#include <iostream>
using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n = 2)
    {
        this->n = n;
        A = new int[n];
    }

    ~Diagonal()
    {
        delete[] A;
    }

    void get(int i, int j);
    void set(int i, int j, int x);
    void display();
};

void Diagonal::get(int i, int j)
{
    if (i == j)
        cout << A[i - 1] << endl;

    else
        cout << "0 " << endl;
}

void Diagonal::set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

void Diagonal::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[i] << " ";

            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    Diagonal d(4);

    d.set(1, 1, 8);
    d.set(2, 2, 5);
    d.set(3, 3, 9);
    d.set(4, 4, 7);

    d.get(2, 3);
    d.get(2, 2);

    d.display();

    return 0;
}