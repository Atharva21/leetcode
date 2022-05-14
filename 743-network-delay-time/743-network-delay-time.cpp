class Solution {
private:
    int mp[100][100];
    int n;
    int bfs(int node) {
        vector<int> vis(n+1, -1);
        queue<int> q;
        q.push(node);
        vis[node] = 0;
        while(!q.empty()) {
            int src = q.front();q.pop();
            for(int dest=1;dest<=n;++dest) {
                if(mp[src][dest] == -1) continue;
                if(vis[dest] == -1 || vis[dest] > (vis[src] + mp[src][dest])) {
                    vis[dest] = (vis[src] + mp[src][dest]);
                    q.push(dest);
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;++i) {
            if(vis[i] == -1) return -1;
            ans = max(ans, vis[i]);
        }
        return ans;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        this->n = n;
        memset(mp, -1, sizeof(mp));
        for(auto& time: times) {
            mp[time[0]][time[1]] = time[2];
        }
        return bfs(k);
    }
};