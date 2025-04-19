class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long pairs=0;
        for(int i=0;i<n-1;i++){
            int nlow=lower-nums[i];
            int nupp=upper-nums[i];
            int right=upper_bound(nums.begin()+i+1,nums.end(),nupp)-nums.begin();
            int maxi=right-i-1;
           int left=lower_bound(nums.begin()+i+1,nums.end(),nlow)-nums.begin();  
           int mini=left-i-1;
           pairs+=maxi-mini;
        }
        return pairs;
    }
};
