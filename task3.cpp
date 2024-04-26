#include <iostream>

using namespace std;

class Vec
{
    int capacity;
    int length;
    int *mem;

public:
    Vec(int _length) : capacity(_length),
                       length(_length),
                       mem(new int[capacity])
    {
        for (int i = 0; i < capacity; i++)
        {
            mem[i] = i;
        }
    }

    int &first()
    {
        return mem[0];
    }

    const int &first() const
    {
        return mem[0];
    }

    int &last()
    {
        return mem[length - 1];
    }

    const int &last() const
    {
        return mem[length - 1];
    }

    int &Capacity()
    {
        return capacity;
    }

    bool contains(int x)
    {
        for (int i = 0; i < length; i++)
        {
            if (mem[i] == x)
            {
                return true;
            }
        }
        return false;
    }

    double Sum()
    {
        double sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += mem[i];
        }
        return sum;
    }

    double average()
    {
        double av;
        av = Sum() / length;
        return av;
    }

    void reverse()
    {
        for (int i = 0; i < length; i++)
        {
            cout << mem[i] << " ";
        }
        cout << endl;

        int start = 0;
        int end = length - 1;

        while (start < end)
        {

            int rev = mem[start];
            mem[start] = mem[end];
            mem[end] = rev;

            start++;
            end--;
        }

        for (int i = 0; i < length; i++)
        {
            cout << mem[i] << " ";
        }
    }

    ~Vec()
    {
        delete[] mem;
    }

    bool empty()
    {
        return length <= 0;
    }

    Vec(const Vec &other) = delete;
    Vec &operator=(const Vec &other) = delete;
};

int main()
{
    Vec vec(10);

    cout << "First element: " << &vec.first() << endl;
    cout << "Last element: " << &vec.last() << endl;
    cout << "Capacity: " << vec.Capacity() << endl;
    cout << vec.empty() << endl;
    cout << vec.contains(11) << endl;
    cout << "The sum of the values of the array: " << vec.Sum() << endl;
    cout << "The average value of the array: " << vec.average() << endl;
    vec.reverse();

    return 0;
}