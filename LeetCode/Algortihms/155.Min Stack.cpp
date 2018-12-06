/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
  */

class MinStack {
private:
    stack<int> st;
    stack<int> st_min;

public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        if(st_min.empty() || number<=st_min.top())   st_min.push(number);
        st.push(number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        if(st.top()==st_min.top())  st_min.pop();
        int x = st.top();
        st.pop();
        return x;
    }

    /*
     * @return: An integer
     */
    int getMin() {
        // write your code here
        return st_min.top();
    }

    int top() {
        return st.top();
    }
};
