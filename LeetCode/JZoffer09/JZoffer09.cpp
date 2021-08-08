class CQueue {
public:
    stack<int> stack1, stack2;

    CQueue() {
            
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        if(stack2.empty()) {
            return -1;
        } else {
            int del = stack2.top();
            stack2.pop();
            return del;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
