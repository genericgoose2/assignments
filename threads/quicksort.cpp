#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<future>
#include <thread>
using namespace std;
//sorting using threads
void printv(vector<int> vec)
{
    for(auto v:vec) cout << v << " ";
    cout << endl;
}

void swap(vector<int> &v, int a, int b)
{
    int tmp;
    tmp = v.at(a);
    v.at(a) = v.at(b);
    v.at(b) = tmp;
}

void quicksort(vector<int> &vec, int low, int high)
{

    thread::id thread_id = this_thread::get_id();
    cout << "Thread id " << thread_id << " vector ";
    printv(vec);
    if(low >= high) return;
    int pivot = vec.at(high);
    int left = low, right = high;
    while(left < right)
    {
        while(vec.at(left) <= pivot && left < right) left++;
        while(vec.at(right) >= pivot && left < right) right--;
        swap(vec, left, right);

    }
    swap(vec, left, high);
    auto a = async(launch::async, [&vec, low, left](){quicksort(vec, low, left-1);});
    auto b = async(launch::async, [&vec, left, high](){quicksort(vec, left+1, high);});
    
}



int main()
{
    vector<int> test = {10,9,4,8,3,5};
    cout << "Initial vector ";
    printv(test);
    quicksort(test, 0, test.size()-1);
    cout << "Result ";
    printv(test);
    return 0;
}