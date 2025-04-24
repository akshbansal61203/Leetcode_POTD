class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt=0;
        map<int,int>mp;
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int l=0,r=0;
        while(r<n){
           mp[nums[r]]++;
            while(mp.size()==st.size()){
                cnt+=n-r;
                mp[nums[l]]--;
                if(mp[nums[l]]<=0)mp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};
