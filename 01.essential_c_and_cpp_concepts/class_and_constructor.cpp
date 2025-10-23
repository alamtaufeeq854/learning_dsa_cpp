// Class and Constructor
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int mLength;
    int mBreadth;

public:
    Rectangle()
    {
        mLength = 0;
        mBreadth = 0;
    }
    Rectangle(int length, int breadth)
    {
        mLength = length;
        mBreadth = breadth;
    }
    int area()
    {
        return mLength * mBreadth;
    }

    int perimeter()
    {
        return 2 * (mLength + mBreadth);
    }
    void setLength(int length)
    {
        mLength = length;
    }

    void setBreadth(int breadth)
    {
        mBreadth = breadth;
    }

    int getLength()
    {
        return mLength;
    }

    int getBreadth()
    {
        return mBreadth;
    }
    ~Rectangle()
    {
        cout << "Destructor";
    }
};

int main()
{
    Rectangle r(10, 5);

    cout << "Area is " << r.area() << endl;
    cout << "Perimeter is " << r.perimeter() << endl;
    r.setLength(8);
    cout << "Length is " << r.getLength() << endl;

    return 0;
}