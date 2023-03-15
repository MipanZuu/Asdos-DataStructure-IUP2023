#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, input;
    deque<int>myDq;
    string command;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push_front")
        {
            cin >> input;
            myDq.push_front(input);
        } else if (command == "push_back")
        {
            cin >> input;
            myDq.push_back(input);
        } else if (command == "pop_front")
        {
            myDq.pop_front();
        } else if (command == "pop_back")
        {
            myDq.pop_back();
        }
    }
    while (!myDq.empty())
    {
        cout << myDq.front() << endl;
        myDq.pop_front();
    }
}