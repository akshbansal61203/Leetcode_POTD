class Solution {
public:
    int f(int ind,int n,vector<vector<int>>&dp,vector<int>&nums,int target){
        if(ind==n){
            if(target==0)return true;
            return false;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int take=0,nottake=0;
        if(target>=nums[ind]){
            take=f(ind+1,n,dp,nums,target-nums[ind]);
        }
        nottake=f(ind+1,n,dp,nums,target);
        return dp[ind][target]=take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2)return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        if(f(0,n,dp,nums,sum/2)>0)return true;
        return false;
    }
};
