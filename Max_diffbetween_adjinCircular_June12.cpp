class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,abs(nums[i]-nums[(i+1)%n]));
        }
        return maxi;
    }
};
