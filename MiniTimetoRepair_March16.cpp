class Solution {
public:
    bool check(vector<int>& ranks, long long cars,long long time){
        int c=0;
        for(int i=0;i<ranks.size();i++){
            long long x=time/ranks[i];
            long long y=sqrt(x);
            c+=y;
            if(c>=cars)return true;
        }
        return c>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long r=(long long)(*max_element(ranks.begin(),ranks.end()))*cars*cars;
        long long l=*min_element(ranks.begin(),ranks.end());
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long car=(long long)cars;
            if(check(ranks,car,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
