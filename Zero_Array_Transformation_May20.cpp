class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int cummulative=0;
        vector<int>diff(nums.size(),0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(r+1<nums.size())diff[r+1]+=1;
            diff[l]-=1;
        }
       // cummulative=diff[0];
        for(int i=0;i<nums.size();i++){
            cummulative+=diff[i];
            nums[i]=max(0,nums[i]+cummulative);
            if(nums[i])return false;
        }
        return true;
    }
};
