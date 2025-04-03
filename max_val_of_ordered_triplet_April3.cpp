class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=max(nums[0],nums[1]);
        long long maxdiff=max(0,nums[0]-nums[1]);
        long long result=0;
        for(int i=2;i<nums.size();i++){
            result=max(result,maxdiff*nums[i]);
            maxdiff=max(maxdiff,maxi-nums[i]);
            maxi=max(maxi,(long long)nums[i]);
        }
        return result;
    }
};
