class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0, ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                ans += nums[i];
            } else {
                maxi = max(maxi, ans);
                ans = nums[i];
            }
        }
        return max(maxi, ans);
    }
};
