class myStack {
    queue<int> q;

  public:

    void push(int x) {
        q.push(x);
        
        int n=q.size();
        
        for(int i = 0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if(!q.empty()){
            q.pop();
        }
    }

    int top() {
        if(q.empty()){
            return -1;
        }
        return q.front();
    }

    int size() {
        return q.size();
    }
};
