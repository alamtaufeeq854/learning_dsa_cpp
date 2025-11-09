// Lower Triangular Matrix In C++ By column Major Formula
#include <iostream>
using namespace std;

class LowerTriangle
{
private:
    int *A;
    int n;

public:
    LowerTriangle(int n = 2)
    {
        this->n = n;
        A = new int[n];
    }

    ~LowerTriangle()
    {
        delete[] A;
    }

    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
};

void LowerTriangle::set(int i, int j, int x)
{
    if (i >= j)
        A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

int LowerTriangle::get(int i, int j)
{
    if (i >= j)
        return A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];

    else
        return 0;
}

void LowerTriangle::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";

            else
                cout << "0 ";
        }
        cout << endl;
    }

    cout << endl
         << endl;
}

int main()
{
    int n;
    cout << "Enter Dimension: ";
    cin >> n;

    LowerTriangle lt(n);

    int x;

    cout << "Enter elements column-wise (only lower-triangular part): " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> x;
            lt.set(i, j, x);
        }
    }

    cout << endl
         << endl;
    lt.display();

    return 0;
}
