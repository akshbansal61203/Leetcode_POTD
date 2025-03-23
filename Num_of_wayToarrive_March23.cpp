class Solution {
public:
    const int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<int>count(n,0);
        dist[0]=0;
        count[0]=1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        pq.push({0,0});
        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto el:adj[node]){
                int ngb=el.first;
                int weight=el.second;
                if(dis+weight<dist[ngb]){
                    dist[ngb]=dis+weight;
                    pq.push({dist[ngb],ngb});
                    count[ngb]=count[node];
                    count[ngb]%=M;
                }
                else if(dis+weight==dist[ngb]){
                    count[ngb]+=count[node];
                    count[ngb]%=M;
                }
            }
        }
        return count[n-1];
    }
};
