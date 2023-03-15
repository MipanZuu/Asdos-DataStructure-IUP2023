/*
    b.cpp
    2023-03-06
    Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    deque<ll>myDq;
    deque<ll>myDqTemp;
    ll n, x, y;
    string command;

    cin >> n;
    while (n--)
    {
        cin >> command;
        if (command == "add")
        {
            cin >> x >> y;
            for (int i = 0; i < y; i++)
            {
                myDq.push_back(x);
                myDqTemp.push_front(x);
            }
            cout << myDq.size() << endl;
        } 
        else if (command == "del")
        {
            cin >> y;
            cout << myDq.front() << endl;
            for (int i = 0; i < y; i++)
            {
                myDq.pop_front();
                myDqTemp.pop_back();
            }
        } else if (command == "rev")
        {
            swap(myDq, myDqTemp);
        } 
    }
    return 0;
}