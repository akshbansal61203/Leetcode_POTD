class Solution {
public:
    int s(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>>mp;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int sum=s(i);
            cout<<sum<<endl;
            mp[sum].push_back(i);
            int x=mp[sum].size();
            maxi=max(maxi,x);
        }
        int c=0;
        for(auto&[a,b]:mp){
            if(b.size()==maxi)c++;
        }
        return c;
    }
};
