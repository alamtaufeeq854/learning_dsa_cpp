// Template Class
#include <iostream>
using namespace std;

template <class T>
class Arithmatic
{
private:
    T mNum1;
    T mNum2;

public:
    Arithmatic(T mNum1, T mNum2);
    T add();
    T sub();
};

template <class T>
Arithmatic<T>::Arithmatic(T mNum1, T mNum2)
{
    this->mNum1 = mNum1;
    this->mNum2 = mNum2;
}

template <class T>
T Arithmatic<T>::add()
{
    return mNum1 + mNum2;
}

template <class T>
T Arithmatic<T>::sub()
{
    return mNum1 - mNum2;
}

int main()
{
    Arithmatic<int> a(100, 15);

    cout << "Add " << a.add() << endl;
    cout << "Subtraction " << a.sub() << endl;

    Arithmatic<float> b(10.568, 1.25);

    cout << "Add " << b.add() << endl;
    cout << "Subtraction " << b.sub() << endl;

    return 0;
}