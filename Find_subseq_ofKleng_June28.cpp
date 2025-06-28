class Solution {
public:
   
    static bool comp(pair<int, int>& a, pair<int, int>& b){
            return a.first>b.first;
    }
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),comp);
        vector<int>ind;
        int i=0;
        while(k--){
            ind.push_back(arr[i].second);
            i++;
        }
        sort(begin(ind),end(ind));
        vector<int>ans;
        for(auto it:ind){
            ans.push_back(nums[it]);
        };
        return ans;
    }
};
