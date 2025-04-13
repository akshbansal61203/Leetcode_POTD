const long long mod =   1000000007; 
class Solution {
public:
    long long power(int n,long long x){
        if(x==1)return n;
        long long even=power(n,x/2)%mod;
        long long y=(even*even)%mod;
        if(x%2){
            return (n*y)%mod;
        }else{
            return (y)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        if(n==1)return 5;
        long long d=(n+1)/2;
        long long x=n-d;
        long long ans=power(5,d);
        long long z=power(4,x);
        ans*=z;
        ans%=mod;
        return ans;
    }
};
