class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,mid=0,n=nums.size(),j=n-1;
        while(i<n&&j>=0&&mid<n){
            if(mid>=i&&mid<=j&&nums[mid]==0){
                swap(nums[i],nums[mid]);
                i++;
            }else if(mid>=i&&mid<=j&&nums[mid]==2){
                swap(nums[j],nums[mid]);
                j--;
            }else mid++;
        }
        return ;
    }
};
