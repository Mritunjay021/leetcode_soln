class Solution {
public:
    string clearStars(string s) 
    {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        
        for(int i = 0; i < s.length(); i++) 
        {
            if(s[i] != '*') 
            {
                pq.push({s[i], -i});  
            } 
            else 
            {
                if(!pq.empty()) 
                {
                    pq.pop();  
                }
            }
        }
        
        vector<int> positions;
        while(!pq.empty()) 
        {
            positions.push_back(-pq.top().second);  
            pq.pop();
        }
        
        sort(positions.begin(), positions.end());
        
        string str = "";
        for(int pos : positions) 
        {
            str += s[pos];
        }
        
        return str;
    }
};