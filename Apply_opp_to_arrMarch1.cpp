class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int i=0;
        int j=i+1;
        while(i<n-1){
            //if(nums[j]==0)j--;
            if(nums[i]){
                i++;
                j=i+1;
            }
            else{
                while(j<n&&nums[j]==0){
                    j++;
                }
                if(j==n)break;
                swap(nums[i],nums[j]);
                i++;
                //j=i+1;
            }
        }
        return nums;
    }
};
