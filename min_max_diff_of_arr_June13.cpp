class Solution {
public:
    bool check(int sum,vector<int>&nums,int p,int n){
        int cnt=0,i=0;
        while(i+1<n){
            if(nums[i+1]-nums[i]<=sum){
                cnt++;
                i+=2;
            }
            else i++;
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(n==1)return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0,r=nums[n-1]-nums[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums,p,n)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
