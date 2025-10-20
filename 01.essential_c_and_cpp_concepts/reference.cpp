// Reference
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a; // reference

    // 'r' is nothing but alias or nickname of 'a'

    a++;
    cout << a << " " << r << endl;
    r++;
    cout << a << " " << r << endl;

    return 0;
}