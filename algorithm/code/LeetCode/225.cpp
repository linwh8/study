#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {
  }
  
  /** Push element x onto stack. */
  void push(int x) {
    q.push(x);
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    queue<int> q_temp;
    int qsize = q.size();

    for (int i = 0; i < qsize - 1; i++) {
      q_temp.push(q.front());
      q.pop();
    }

    int ans = q.front();
    q.pop();

    for (int i = 0; i < qsize - 1; i++) {
      q.push(q_temp.front());
      q_temp.pop();
    }

    return ans;
  }
  
  /** Get the top element. */
  int top() {
    queue<int> q_temp;
    int qsize = q.size();

    for (int i = 0; i < qsize - 1; i++) {
      q_temp.push(q.front());
      q.pop();
    }

    int ans = q.front();
    q_temp.push(q.front());
    q.pop();

    for (int i = 0; i < qsize; i++) {
      q.push(q_temp.front());
      q_temp.pop();
    }

    return ans;
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return q.empty();
  }

private:
  queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

