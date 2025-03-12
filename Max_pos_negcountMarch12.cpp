class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int one=lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        int posi=nums.size()-one;
        int negi=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        return max(posi,negi);
    }
};
