class Solution {
public:
    vector<bool>sieve(int n){
        vector<bool>prime(n+1,true);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=2;j*i<=n;j++){
                    prime[i*j]=0;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isPrime=sieve(right);
        vector<int>res={-1,-1};
        vector<int>primes;
        for(int i=left;i<=right;i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        int mindiff=INT_MAX;
        for(int i=1;i<primes.size();i++){
            int diff=primes[i]-primes[i-1];
            if(diff<mindiff){
                mindiff=diff;
                res={primes[i-1],primes[i]};
            }
        }
        return res;
    }
};
