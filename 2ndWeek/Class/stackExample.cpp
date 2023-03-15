#include <bits/stdc++.h>
using namespace std;

bool validParantheses(string str)
{
	stack<char> myStack;
	for (int i = 0; i < str.length(); i++) {
		if (myStack.empty()) {
			
			myStack.push(str[i]);
		}
		else if ((myStack.top() == '(' && str[i] == ')')
				|| (myStack.top() == '{' && str[i] == '}')
				|| (myStack.top() == '[' && str[i] == ']')) {
			
			myStack.pop();
		}
		else {
			myStack.push(str[i]);
		}
	}
	if (myStack.empty()) {
		return true;
	}
	return false;
}

int main()
{
	string str;
    cin >> str;
	if (validParantheses(str))
		cout << "Valid Paranthesis";
	else
		cout << "Not Valid Paranthesis";
	return 0;
}
