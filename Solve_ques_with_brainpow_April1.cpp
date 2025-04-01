class Solution {
public:
    long long solve(int ind,vector<vector<int>>& q,vector<long long>&dp){
        if(ind>=q.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long take=q[ind][0]+solve(ind+q[ind][1]+1,q,dp);
        long long nottake=solve(ind+1,q,dp);
        return dp[ind]=max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>dp(n+1,-1);
        solve(0,q,dp);
        return dp[0];
    }
};
