class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times)
        adj[it[0]].push_back({it[1],it[2]});
        queue<pair<int,int>> q;
        vector<int> vis(n+1,1e9);
        vis[k]=0;
        q.push({k,0});
        while(!q.empty())
        {
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int nd=it.first;
                int d=it.second;
                if(vis[node]+d<vis[nd])
                {
                    vis[nd]=vis[node]+d;
                    q.push({nd,vis[node]+d});
                }
            }
        }
        int mx=0;
        for(int i=1;i<n+1;i++)
        {
            mx=max(mx,vis[i]);
        }
        if(mx==1e9)
        return -1;
        return mx;
    }
};


// class Solution {
// public:
//     int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) 
//     {
//         // Create adjacency list
//         std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
//         for (auto it : times) {
//             adj[it[0]].push_back({it[1], it[2]});
//         }
        
//         // // Priority queue for Dijkstra's algorithm
//         // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
//         queue<pair<int,int>> pq;
        
//         // Distance vector initialized to a large value
//         std::vector<int> dist(n + 1, INT_MAX);
//         dist[k] = 0;
//         pq.push({0, k});
        
//         while (!pq.empty()) {
//             int d = pq.front().first;
//             int node = pq.front().second;
//             pq.pop();
//             //  greater than recorded, skip
//             // if (d > dist[node]) continue;
            
//             for (auto it : adj[node]) {
//                 int nextNode = it.first;
//                 int edgeWeight = it.second;
                
//                 // Relaxation step
//                 if (dist[node] + edgeWeight < dist[nextNode]) {
//                     dist[nextNode] = dist[node] + edgeWeight;
//                     pq.push({dist[nextNode], nextNode});
//                 }
//             }
//         }
        
//         // Find the maximum distance
//         int maxDist = 0;
//         for (int i = 1; i <= n; ++i) {
//             if (dist[i] == INT_MAX) return -1;
//             maxDist = std::max(maxDist, dist[i]);
//         }
        
//         return maxDist;
//     }
// };