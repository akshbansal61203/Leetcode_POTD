class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        long long sum=0;
        for(int i=n;i>1;i--){
            sum+=(i-1)*4;
        }
        return sum+1;
    }
};
