#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<char> s;
    string str;
    while(n)
    {
        if(n%2==0){
            n=(n-2)/2;
            s.push('G');
        }
        else{
            n=(n-1)/2;
            s.push('N');
        }
    }
    while(!s.empty())
    {
        str+=s.top();
        s.pop();
    }
    cout<<str;
}

