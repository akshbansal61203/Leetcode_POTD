class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        int r=0;
        while(r<n-2){
            if(nums[r]==0){
                nums[r]=!nums[r];
                nums[r+1]=!nums[r+1];
                nums[r+2]=!nums[r+2];
                c++;
            }
            r++;
        }
        if(nums[n-1]!=1||nums[n-2]!=1)return -1;
        return c;
    }
};
