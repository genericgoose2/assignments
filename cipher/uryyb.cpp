#include<iostream>    
#include<array> 
using namespace std;
//simple message cipher 
int main()
{
    char text[] = "hello uryyb HELLO URYYB";
    cout << text << endl;
    for(int i=0; text[i]!='\0';i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            if(text[i]+13 > 'Z') text[i]-=13;
            else text[i]+=13;
        }
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            if(text[i]+13 > 'z') text[i]-=13;
            else text[i]+=13;
        }
        //cout << text[i] << "\n";
    }
    cout << text;
    return 0;
}
