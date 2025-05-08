class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto node=pq.top();
            int time=node.first;
            int row=node.second.first;
            int col=node.second.second;
            pq.pop();
            if(row==n-1&&col==m-1)return time;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int wait=max(moveTime[nr][nc]-time,0);
                    int step=nr+nc;
                    
                    int ntime=wait+time;
                    if(step%2)ntime++;
                    else ntime+=2;
                    if(dist[nr][nc]>ntime){
                        dist[nr][nc]=ntime;
                        pq.push({ntime,{nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
