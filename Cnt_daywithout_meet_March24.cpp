class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(begin(m),end(m));
        long long ans=0,l1=m[0][0],r1=m[0][1],l2=0,r2=0;
        for(int i=1;i<m.size();i++){
            l2=m[i][0];
            r2=m[i][1];
            if(l2>r1){
                ans+=l2-r1-1;
                l1=l2;
                r1=r2;
            }
            else{
                r1=max(r2,r1);
            }
        }
        ans+=max(0LL,1LL*days-r1);
        ans+=max(0,m[0][0]-1);
        return ans;
    }
};
