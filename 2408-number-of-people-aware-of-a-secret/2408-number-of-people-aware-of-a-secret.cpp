#include <deque>
#include <utility>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        std::deque<int> q; // stores the number of people who know the secret and can spread it
        std::deque<std::pair<int, int>> v; // stores the (start sharing day, stop sharing day) for each group
        
        // On day 1, 1 person knows the secret
        q.push_back(1);
        v.push_back({1 + delay, 1 + forget - 1});
        
        // Iterate from day 2 to n
        for (int day = 2; day <= n; ++day) {
            int count = 0;
            
            // Check if the front of the deque is expired (people who can no longer share)
            while (!v.empty() && v.front().second < day) {
                q.pop_front();
                v.pop_front();
            }
            
            // Add the number of people who are in their sharing period
            for (int j = 0; j < q.size(); ++j) {
                int l = v[j].first; // start sharing day
                int r = v[j].second; // stop sharing day
                
                if (l <= day && day <= r) {
                    count = (count + q[j]) % MOD; // Add the count and apply modulo
                }
            }
            
            // Add new people who start sharing the secret today
            if (count > 0) {
                q.push_back(count);
                v.push_back({day + delay, day + forget - 1});
            }
        }
        
        // Sum up the people who still know the secret at the end (those who haven't forgotten)
        long long ans = 0;
        for (int ele : q) {
            ans = (ans + ele) % MOD; // Add the remaining people and apply modulo
        }
        
        return ans;
    }
};