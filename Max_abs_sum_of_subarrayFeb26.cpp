class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSubSum = 0;
        int maxSubSum = -1e9;

        //Kadane's Algo for findig max subarray sum
        for(int i = 0; i < n; i++) {
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        //Kadane's Algo for findig min subarray sum
        int minSubSum =1e9;
        currSubSum = 0;
        for(int i = 0; i < n; i++) {
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum = min(minSubSum, currSubSum);
        }

        return max(maxSubSum, abs(minSubSum));
    }
};
