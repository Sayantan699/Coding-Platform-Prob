class SpecialStack {
  public:
  stack<int> s1;
        stack<int> s2;
    SpecialStack() {
        // Define Stack
        
    }

    void push(int x) {
        // Add an element to the top of Stack
        if(s1.empty()){
            s1.push(x);
            s2.push(x);
        }
        else{
        s1.push(x);
        s2.push(min(x,s2.top()));
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if (!s1.empty()) {
            s1.pop();
            s2.pop();
        }
    }

    int peek() {
        // Returns top element of the Stack
        if(s1.empty())
            return -1;
        else
            return s1.top();
    }

    bool isEmpty() {
        // Check if stack is empty
        return s1.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        if(!s2.empty())
            return s2.top();
        return -1;
    }
};