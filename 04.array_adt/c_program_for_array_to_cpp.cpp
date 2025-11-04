#include <iostream>
using namespace std;

class Array
{
private:
    int *mArray;
    int mSize;
    int mLength;
    void swapElements(int *x, int *y);

public:
    Array()
    {
        mSize = 10;
        mLength = 0;
        mArray = new int[mSize];
    }

    Array(int size)
    {
        mSize = size;
        mLength = 0;
        mArray = new int[mSize];
    }

    ~Array()
    {
        delete[] mArray;
    }

    void display();
    void append(int value);
    void insert(int index, int value);
    int deleteElement(int index);
    int linearSearch(int key);
    int binarySearch(int key);
    int get(int index);
    void set(int index, int value);
    int max();
    int min();
    int sum();
    float avg();
    void reverse();
    void reverseInPlace();
    void insertSorted(int value);
    int isSorted();
    void rearrange();
    Array *merge(Array arr2);
    Array *unionArray(Array arr2);
    Array *diff(Array arr2);
    Array *inter(Array arr2);
};

void Array::display()
{
    cout << "\nElements are\n";
    for (int i = 0; i < mLength; i++)
        cout << mArray[i] << " ";
}

void Array::append(int value)
{
    if (mLength < mSize)
        mArray[mLength++] = value;
}

void Array::insert(int index, int value)
{
    if (index >= 0 && index <= mLength)
    {
        for (int i = mLength; i > index; i--)
            mArray[i] = mArray[i - 1];
        mArray[index] = value;
        mLength++;
    }
}

int Array::deleteElement(int index)
{
    int deletedValue = 0;

    if (index >= 0 && index < mLength)
    {
        deletedValue = mArray[index];
        for (int i = index; i < mLength - 1; i++)
            mArray[i] = mArray[i + 1];
        mLength--;
        return deletedValue;
    }
    return 0;
}

void Array::swapElements(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::linearSearch(int key)
{
    for (int i = 0; i < mLength; i++)
    {
        if (key == mArray[i])
        {
            swapElements(&mArray[i], &mArray[0]);
            return i;
        }
    }
    return -1;
}

int Array::binarySearch(int key)
{
    int low = 0, high = mLength - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == mArray[mid])
            return mid;
        else if (key < mArray[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::get(int index)
{
    if (index >= 0 && index < mLength)
        return mArray[index];
    return -1;
}

void Array::set(int index, int value)
{
    if (index >= 0 && index < mLength)
        mArray[index] = value;
}

int Array::max()
{
    int maximum = mArray[0];
    for (int i = 1; i < mLength; i++)
    {
        if (mArray[i] > maximum)
            maximum = mArray[i];
    }
    return maximum;
}

int Array::min()
{
    int minimum = mArray[0];
    for (int i = 1; i < mLength; i++)
    {
        if (mArray[i] < minimum)
            minimum = mArray[i];
    }
    return minimum;
}

int Array::sum()
{
    int total = 0;
    for (int i = 0; i < mLength; i++)
        total += mArray[i];
    return total;
}

float Array::avg()
{
    return static_cast<float>(sum()) / mLength;
}

void Array::reverse()
{
    int *temp = (int *)malloc(mLength * sizeof(int));
    for (int i = mLength - 1, j = 0; i >= 0; i--, j++)
        temp[j] = mArray[i];
    for (int i = 0; i < mLength; i++)
        mArray[i] = temp[i];
}

void Array::reverseInPlace()
{
    for (int i = 0, j = mLength - 1; i < j; i++, j--)
        swapElements(&mArray[i], &mArray[j]);
}

void Array::insertSorted(int value)
{
    if (mLength == mSize)
        return;
    int i = mLength - 1;
    while (i >= 0 && mArray[i] > value)
    {
        mArray[i + 1] = mArray[i];
        i--;
    }
    mArray[i + 1] = value;
    mLength++;
}

int Array::isSorted()
{
    for (int i = 0; i < mLength - 1; i++)
    {
        if (mArray[i] > mArray[i + 1])
            return 0;
    }
    return 1;
}

void Array::rearrange()
{
    int i = 0, j = mLength - 1;
    while (i < j)
    {
        while (mArray[i] < 0)
            i++;
        while (mArray[j] >= 0)
            j--;
        if (i < j)
            swapElements(&mArray[i], &mArray[j]);
    }
}

Array *Array::merge(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *mergedArray = new Array(mLength + arr2.mLength);

    while (i < mLength && j < arr2.mLength)
    {
        if (mArray[i] < arr2.mArray[j])
            mergedArray->mArray[k++] = mArray[i++];
        else
            mergedArray->mArray[k++] = arr2.mArray[j++];
    }

    for (; i < mLength; i++)
        mergedArray->mArray[k++] = mArray[i];
    for (; j < arr2.mLength; j++)
        mergedArray->mArray[k++] = arr2.mArray[j];

    mergedArray->mLength = k;
    return mergedArray;
}

Array *Array::unionArray(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *unionArr = new Array(mLength + arr2.mLength);

    while (i < mLength && j < arr2.mLength)
    {
        if (mArray[i] < arr2.mArray[j])
            unionArr->mArray[k++] = mArray[i++];
        else if (arr2.mArray[j] < mArray[i])
            unionArr->mArray[k++] = arr2.mArray[j++];
        else
        {
            unionArr->mArray[k++] = mArray[i++];
            j++;
        }
    }

    for (; i < mLength; i++)
        unionArr->mArray[k++] = mArray[i];
    for (; j < arr2.mLength; j++)
        unionArr->mArray[k++] = arr2.mArray[j];

    unionArr->mLength = k;
    return unionArr;
}

Array *Array::inter(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *interArr = new Array(mLength + arr2.mLength);

    while (i < mLength && j < arr2.mLength)
    {
        if (mArray[i] < arr2.mArray[j])
            i++;
        else if (arr2.mArray[j] < mArray[i])
            j++;
        else
        {
            interArr->mArray[k++] = mArray[i++];
            j++;
        }
    }

    interArr->mLength = k;
    return interArr;
}

Array *Array::diff(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *diffArr = new Array(mLength + arr2.mLength);

    while (i < mLength && j < arr2.mLength)
    {
        if (mArray[i] < arr2.mArray[j])
            diffArr->mArray[k++] = mArray[i++];
        else if (arr2.mArray[j] < mArray[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < mLength; i++)
        diffArr->mArray[k++] = mArray[i];

    diffArr->mLength = k;
    return diffArr;
}

int main()
{
    Array *array1;
    int choice, size;
    int value, index;

    cout << "Enter Size of Array: ";
    scanf("%d", &size);
    array1 = new Array(size);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter an element and index: ";
            cin >> value >> index;
            array1->insert(index, value);
            break;

        case 2:
            cout << "Enter index: ";
            cin >> index;
            value = array1->deleteElement(index);
            cout << "Deleted Element is " << value;
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> value;
            index = array1->linearSearch(value);
            cout << "Element index: " << index;
            break;

        case 4:
            cout << "Sum is " << array1->sum();
            break;

        case 5:
            array1->display();
            break;
        }
    } while (choice < 6);

    return 0;
}
