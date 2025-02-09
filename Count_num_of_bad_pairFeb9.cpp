class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }
        mp[nums[0]]=1;
        for(int j=1;j<n;j++){
            int totalbeforej=j;
            int same=mp[nums[j]];
            int badpair=totalbeforej-same;
            ans+=badpair;
            mp[nums[j]]++;
        }
        return ans;
    }
};
