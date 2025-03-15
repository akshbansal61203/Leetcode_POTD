class Solution {
public:
    bool check(vector<int>& nums, int k,int c){
        int cnt=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=c){
                cnt++;
                i+=2;
            }
            else i++;
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int r=*max_element(nums.begin(),nums.end());
        int l=*min_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
