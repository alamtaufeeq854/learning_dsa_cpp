// Sparse Matrix In C++
#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *e;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[num];
    }

    void read()
    {
        cout << "Enter all non-zero elements:\n";
        for (int k = 0; k < num; k++)
        {
            cout << "Row: ";
            cin >> e[k].i;

            cout << "Column: ";
            cin >> e[k].j;

            cout << "Value: ";
            cin >> e[k].x;
        }
    }

    void display()
    {
        int k = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (k < num && e[k].i == i && e[k].j == j)
                    cout << e[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m, n, num;

    cout << "Enter total rows: ";
    cin >> m;

    cout << "Enter total columns: ";
    cin >> n;

    cout << "Enter number of non-zero elements: ";
    cin >> num;

    Sparse s(m, n, num);

    s.read();
    cout << "\nSparse Matrix:\n";
    s.display();

    return 0;
}
