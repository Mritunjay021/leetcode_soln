class MyLinkedList {
public:

    int n=0;
    int arr[1000];

    MyLinkedList() 
    {
          
    }
    
    int get(int index) 
    {
        if(index>=0 && index<n)
        return arr[index];
        else
        return -1;
    }
    
    void addAtHead(int val) 
    {
        if(n>=1000)
        return;

        for(int i=n;i>0;i--)
        {
            arr[i]=arr[i-1];
        } 
        arr[0]=val;
        n++;
    }
    
    void addAtTail(int val) 
    {
        if(n>=1000)
        return;

        arr[n]=val;
        n++;    
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index>n)
        return ;

        if(index==n)
        {
            arr[n]=val;
            n++;
            return;
        }

        if(index<0)
        {
            addAtHead(val);
            return;
        }

        for(int i=n;i>index;i--)
        {
            arr[i]=arr[i-1];
        } 
        arr[index]=val;
        n++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index>=n || index<0)
        return ;

        for(int i=index;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        } 
        n--;   
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */