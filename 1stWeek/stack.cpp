/*
    stack.cpp
    2023-02-06
    Denta Bramasta
*/

#include <bits/stdc++.h>
#define size 5
int stack[size],top = -1;
using namespace std;

struct stack {
    int s[size];
    int top;
}st;

int stack_empty()
{
if(st.top == -1)
    return 1;
else
    return 0;
}

int stack_full()
{
    if(st.top == (size-1))
        return 1;
    else
        return 0;
}

void push(int item)
{
    if(stack_full()) return;
    st.top++;
    st.s[st.top]=item;
    cout << item << endl;

//     printf("%d", item);
//     scanf("%d", &item);
//     cin >> item;
}
int main() {
    push(99);
    push(10);
    push(100);
    push(5);
    push(1000);
    push(1);
    
    return 0;
}