class Solution {
public:
    int splitNum(int num) 
    {
        vector<int> v;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(num!=0)
        {
            int n=num%10;
            pq.push(n);
            num=num/10;
        }    
        int n1=0,n2=0;
        int sz=pq.size();
        for(int i=0;i<sz;i+=2)
        {
            n1=n1*10+pq.top();
            pq.pop();
            if(pq.size()>0)
            {
                n2=n2*10+pq.top();
                pq.pop();
            }
        }
        return n1+n2;
    }
};