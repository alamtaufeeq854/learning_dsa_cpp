// C++ Program For Array
#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *mArray;
    int mSize;
    int mLength;

public:
    Array()
    {
        mSize = 10;
        mArray = new T[10];
        mLength = 0;
    }

    Array(int size)
    {
        mSize = size;
        mLength = 0;
        mArray = new T[mSize];
    }

    ~Array()
    {
        delete[] mArray;
    }

    void display();
    void insert(int index, T value);
    T deleteElement(int index);
};

template <class T>
void Array<T>::display()
{
    for (int i = 0; i < mLength; i++)
        cout << mArray[i] << " ";
    cout << endl;
}

template <class T>
void Array<T>::insert(int index, T value)
{
    if (index >= 0 && index <= mLength)
    {
        for (int i = mLength - 1; i >= index; i--)
            mArray[i + 1] = mArray[i];
        mArray[index] = value;
        mLength++;
    }
}

template <class T>
T Array<T>::deleteElement(int index)
{
    T deletedValue = 0;
    if (index >= 0 && index < mLength)
    {
        deletedValue = mArray[index];
        for (int i = index; i < mLength - 1; i++)
            mArray[i] = mArray[i + 1];
        mLength--;
    }
    return deletedValue;
}

int main()
{
    Array<char> array(10);

    array.insert(0, 'a');
    array.insert(1, 'c');
    array.insert(2, 'd');
    array.display();
    cout << array.deleteElement(0) << endl;
    array.display();

    return 0;
}
