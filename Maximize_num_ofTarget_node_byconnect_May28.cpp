class Solution {
public:
   int bfs(int curr, vector<vector<int>>& adj, int d, int N) {
        queue<pair<int, int>> que;
        que.push({curr, 0});
        vector<bool> visited(N, false);
        visited[curr] = true;
        int count = 0; 
        while(!que.empty()) {
            int currNode = que.front().first;
            int dist = que.front().second;
            que.pop();
            if(dist > d) {
                continue;
            }
            count++;
            for(auto &ngbr : adj[currNode]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                }
            }
        }
        return count;
    }
    vector<int> cnt(vector<vector<int>>&edge,int k){
        int n=edge.size()+1;
        vector<int>res(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            res[i]=bfs(i,adj,k,n);
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<int>res1=cnt(edges1,k);
        vector<int>res2=cnt(edges2,k-1);
        int maxi=*max_element(res2.begin(),res2.end());
        for(int i=0;i<res1.size();i++){
            res1[i]+=maxi;
        }
        return res1;
    }
};
