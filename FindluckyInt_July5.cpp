class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        for(auto &it:arr){
            mp[it]++;
        }
        int x=0;
        for(auto &[a,b]:mp){
            if(a==b)x=max(x,a);
        }
        return (x)?x:-1;
    }
};
