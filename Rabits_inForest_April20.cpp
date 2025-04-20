class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int sum=0;
        map<int,int>mp;
       for(auto it:answers)mp[it]++;
       for(auto &[a,b]:mp){
            int same=a+1;
            int q=(b+same-1)/same;
            sum+=same*q;
       }
        return sum;
    }
};
