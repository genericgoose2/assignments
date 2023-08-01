#include<iostream>
#include <thread>
#include <future>
using namespace std;

void func1(promise<int> &p, int n)
{
    p.set_value(n);
}

void func2(future<int> &f)
{
    f.wait();
    cout << "future number " << f.get() << endl; 
}

int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();
    
    thread t1(func1, ref(prom), 3);
    thread t2(func2, ref(fut));
    t1.join();
    t2.join();

    return 0;
}
