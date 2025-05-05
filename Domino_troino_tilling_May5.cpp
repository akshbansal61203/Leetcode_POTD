#define mod 1000000007
class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==1||n==2)return dp[n]=n;
        if(n==3)return dp[n]= 5;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(2*f(n-1,dp)%mod+f(n-3,dp)%mod)%mod;
    }
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        f(n,dp);
        return dp[n];
    }
};
