class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n,-1);
        next[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
           next[i]=max(next[i+1],nums[i]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(next[i]>nums[i])maxi=max(maxi,next[i]-nums[i]);
        }
        return (maxi==INT_MIN)?-1:maxi;
    }
};
