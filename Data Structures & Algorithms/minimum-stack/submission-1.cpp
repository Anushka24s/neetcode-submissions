class MinStack {
private:
    vector<int> stack{};
    vector<int> minStack;
public:
    MinStack() {
        stack = {};
        minStack = {INT_MAX};
    }
    
    void push(int value) {
        stack.push_back(value);

        if(minStack.at(minStack.size()-1) >= value){
            minStack.push_back(value);
        }
    }
    
    void pop() {
        int poppedElement = stack.at(stack.size()-1);
        stack.pop_back();

        if(minStack.at(minStack.size()-1) == poppedElement){
            minStack.pop_back();
        }
    }
    
    int top() {
        return stack.at(stack.size()-1);
    }
    
    int getMin() {
        return minStack.at(minStack.size()-1);
    }
};

