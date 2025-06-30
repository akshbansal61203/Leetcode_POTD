class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool f=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                f=1;
            }
        }
        if(f==0)return 0;
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int ans=0;
        for(auto it:nums){
           if(mp.find(it+1)!=mp.end()){
            ans=max(ans,mp[it]+mp[it+1]);
           }
           if(mp.find(it-1)!=mp.end()){
            ans=max(ans,mp[it]+mp[it-1]);
           }
        }
        return ans;
    }
};
