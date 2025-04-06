class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int maxi=0;
        int lastind=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=max(maxi,dp[i]);
                lastind=i;
            }
        }
        vector<int>ans;
        while(hash[lastind]!=lastind){
            ans.push_back(nums[lastind]);
            lastind=hash[lastind];
        }
        ans.push_back(nums[lastind]);
        return ans;
    }
};
