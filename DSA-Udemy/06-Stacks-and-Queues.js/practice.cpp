#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> s1, s2;

public:
    Queue() {}
    void enqueue(int value)
    {
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(value);
        return;
    }
    void dequeue()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
    void peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        cout << s2.top() << endl;
    }
};
class Stack
{
    queue<int> q1, q2;

public:
    void push(int data)
    {
        q2.push(data);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
        return;
    }
    void pop(){
        q1.pop();
        return;
    }
    void top(){
        cout << q1.front() << endl;
        return;
    }
};
int main()
{
    Queue q;
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.peek();
    q.dequeue();
    q.peek();

    Stack s;
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    s.top();
    s.pop();
    s.top();

    return 0;
}