class Solution {
public:
    int f(vector<int>&nums,int ind,int xored){
        if(ind==nums.size()){
            return xored;
        }
        int take=f(nums,ind+1,xored^nums[ind]);
        int notake=f(nums,ind+1,xored);
        return take+notake;
    }
    int subsetXORSum(vector<int>& nums) {
        return f(nums,0,0);
    }
};
