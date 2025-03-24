class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) 
    {
        stack<int> st;

        for(int i=0;i<as.size();i++)
        {
            if(st.empty() || as[i]>0 || st.top()<0)
            st.push(as[i]);
            
            else
            {   
                while(!st.empty() && st.top() > 0 && st.top() <abs(as[i]))
                st.pop();

                if(!st.empty() && st.top() == abs(as[i]))
                {
                    st.pop();
                    continue;
                }

                if(!st.empty() && st.top() > abs(as[i]))
                continue;

                st.push(as[i]);
            }
        }    

        vector<int> v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(),v.end());
        return v;
    }
};