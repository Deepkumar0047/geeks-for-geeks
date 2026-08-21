class myQueue {
    
    stack<int> s1, s2;

public:
    myQueue() {
        
    }

    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty())
            return;

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front() {
        if (s1.empty() && s2.empty())
            return -1;

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    int size() {
        return s1.size() + s2.size();
    }
};