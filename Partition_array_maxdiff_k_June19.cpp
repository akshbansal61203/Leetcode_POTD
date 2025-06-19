class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        //vector<int>a(n,0);
        int i=0,j=0,grp=1;
        while(j<n){
            if(nums[j]-nums[i]>k){
                grp++;
                i=j;
            }
            j++;
        }
        return grp;
    }
};
