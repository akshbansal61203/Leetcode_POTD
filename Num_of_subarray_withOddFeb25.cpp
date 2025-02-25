#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size(),prefix_sum=0;
       int ans=0;
       int even=1,odd=0;
       for(auto it:arr){
        prefix_sum+=it;
        if(prefix_sum%2==0){
            ans+=odd;
            even++;
        }else{
            ans+=even;
            odd++;
        }
        ans%=mod;
       }
       return ans%mod;
    }
};
