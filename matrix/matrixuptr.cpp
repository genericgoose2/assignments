#include<iostream>
#include <memory>
using namespace std;

class Matrix 
{
    int lines, columns, pos;
    unique_ptr<int[]> array;
    public:
    
    Matrix(int c, int l)
    {
        pos = 0;
        lines = l;
        columns = c;
        array = unique_ptr<int[]>( new int[c*l] );
    }
    
    ~Matrix()
    {
        delete[] &array;
    }

    template<typename ... T>
    void add(T ... args)
    {
        for(int arg : {args...}) 
        {
            array[pos] = arg;
            pos++;
            if(pos >= lines*columns) pos = 0;
        }
    }

    int* getptr(int line, int column)
    {
        return &array[line*lines+column];
    }

    void get(int line, int column)
    {
        int* tmp = getptr(line, column);
        cout << *tmp;
    }

    void set(int line, int column, int val)
    {
        int* tmp = getptr(line,column);
        *tmp = val;
    }

    void print()
    {
        for(int i = 0; i < columns*lines; i++)
        {
            cout << array[i] << " ";
            if((i+1)%3==0) cout << endl;
        }
        cout << endl;
    }

    void printC()
    {
        for(int l = 0; l < lines; l++)
        {
            for(int c = 0; c < columns; c++)
            {
                get(l,c);
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
};

int main()
{
    Matrix mat(3,3);
    mat.add(1,2,3,4,5,6,7,8,9);
    mat.printC();
    mat.add(9,8,7,6,5,4,3,2,1);
    mat.print();
    mat.add(1,2,3);
    mat.printC();
    mat.add(1,2,3);
    mat.printC();
    mat.add(1,2,3);
    mat.printC();

    mat.set(1,1,5);
    mat.printC();
    return 0;
}
