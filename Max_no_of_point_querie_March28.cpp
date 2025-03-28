 #define pp pair<int,pair<int,int>> 
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        int m=grid.size();
        int n=grid[0].size();
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++)q.push_back({queries[i],i});
        sort(begin(q),end(q));
        vector<int>ans(queries.size(),0);
        int point=0;
        for(int i=0;i<q.size();i++){
            int qval=q[i].first;
            int idx=q[i].second;
            while(!pq.empty()&&pq.top().first<qval){
                int i=pq.top().second.first;
                int j=pq.top().second.second;
                pq.pop();
                point++;
                 for(int x=0;x<4;x++) {
                    int i_ = i + dr[x];
                    int j_ = j + dc[x];
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !vis[i_][j_]) {
                        pq.push({grid[i_][j_], {i_, j_}});
                        vis[i_][j_] = true;
                    }
                }
            }
              ans[idx] = point;
        }
        return ans;
    }
};
