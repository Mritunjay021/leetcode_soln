class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});

        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
       int k=0;
        for(int i=0;i<v.size();i++){
            while(v[i].first){
                s[k]=v[i].second;
                k++;
                v[i].first--;
            }
        }
        return s;
    }
};