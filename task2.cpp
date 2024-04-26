#include <iostream>

using namespace std;

class IntArray 
{
    int lenght;
    int *mem;

public:

    IntArray(int size):
    lenght(size),
    mem(new int [lenght])
    {
        for(int i=0; i<lenght; i++)
        {
            mem[i]=i;
        }
    }

    IntArray(int size, int val):
    lenght(size),
    mem(new int [lenght])
    {
        for(int i=0; i<lenght; i++)
        {
            this->mem[i] = val;
        }
    }

    /*void fill(int val)
    {
        for(int i=0; i<lenght; i++)
        {
            this->mem[i] = val;
        }
    }*/

    void iota(int start)
    {
        int i=0;
        for(; start<lenght; start++)
        {
            this->mem[i] = start*start;
            i++;
        }
    }


    void Print()
    {
        for(int i=0; i<lenght; i++)
        {
            cout<<mem[i]<<" ";
        }
    }

    ~IntArray()
    {
        delete[] mem;
    }

};

class DoubleArray : public IntArray
{
    int lenght=5;
    int *mem;
    int *new_arr;

public:

    DoubleArray(double val):
    mem(new int [lenght])
    {
        for(int i=0; i<lenght; i++)
        {
            this->mem[i] = val;
        }
    }

    void iota(double start)
    {
        int i=0;
        for(; start<lenght; start++)
        {
            this->mem[i] = start*start;
            cout<<mem[i]<<" ";
            i++;
        }
        cout<<endl;
    }

    void resize(int new_len)
    {
        this->lenght = new_len;
        new_arr = new int[new_len];
        for(int i=0; i<lenght; i++)
        {
            this-> new_arr[i] = i;
            this->mem[i]=new_arr[i];
            cout<<mem[i]<<" ";
        }
    }

    ~DoubleArray()
    {
        delete[] mem;
        delete[] new_arr;
    }
};

int main()
{
    int size;
    cout<<"Enter size: ";
    cin>>size;

    int val =5;

    DoubleArray arr(val);

    //int start=0;

    //arr.iota();

    //arr.Print();

    arr.iota(0);
    arr.resize(5);

    return 0;
}