#include<iostream>

using namespace std;

int main()
{
//  function pointer           lambda starting with [] 
    int (*addptr)(int, int) = [](int a, int b) {return a+b;};
    int (*subptr)(int, int) = [](int a, int b) {return a-b;};
    int a,b;
    char op;

    while((op != '+') && (op != '-'))
    {
        cout << "Operation " << endl;
        cin >> op;
    }

    cout << "A " << endl;
    cin >> a;
    cout << "B " << endl;
    cin >> b;

    switch(op)
    {
        case '+':
        cout << addptr(a,b);
        break;
        case '-':
        cout << subptr(a,b);
        break;
    }
    
    return 0;
}
