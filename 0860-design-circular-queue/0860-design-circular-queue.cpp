class MyCircularQueue {
public:

    queue<int> q;
    int sz;
    MyCircularQueue(int k) 
    {
        sz=k;    
    }
    
    bool enQueue(int value) 
    {
        if(q.size()<sz)
        {
            q.push(value);
            return true; 
        }
        else
        return false;    
    }
    
    bool deQueue() 
    {
        if(!q.empty())
        {
            q.pop();
            return true;
        }    
        else
        return false;
    }
    
    int Front() 
    {
        return q.empty()?-1:q.front();    
    }
    
    int Rear() 
    {
        return q.empty()?-1:q.back();    
    }
    
    bool isEmpty() 
    {
        return q.size()==0;    
    }
    
    bool isFull() 
    {
        return q.size()==sz;   
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */