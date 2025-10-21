// Functions
#include <iostream>
using namespace std;

int add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int num1 = 10, num2 = 51, sum;
    sum = add(num1, num2);
    cout << "Sum is " << sum << endl;

    return 0;
}