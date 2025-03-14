class Solution {
public:
    bool check(vector<int>& candies, long long k,int c){
        long long total_piles=0;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>=c){
                total_piles+=(candies[i]/c);
            }
        }
        return total_piles>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long r=1e7;
        long long l=1;
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(candies,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
