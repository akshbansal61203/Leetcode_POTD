class Solution {
public:
    bool solve(int i,int n,vector<bool>&used,vector<int>&result){
        if(i>=result.size()){
            return true;
        }
        if(result[i]!=-1){
            return solve(i+1,n,used,result);
        }
        for(int num=n;num>=1;num--){
            if(used[num])continue;
            used[num]=1;
            result[i]=num;
            if(num==1){
                if(solve(i+1,n,used,result))return true;
            }
            else{
                int j=result[i]+i;
                if(j<result.size()&&result[j]==-1){
                    result[j]=num;
                    if(solve(i+1,n,used,result))return true;
                    result[j]=-1;
                }
            }
            used[num]=0;
            result[i]=-1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>result(2*n-1,-1);
        vector<bool>used(n+1,false);
        solve(0,n,used,result);
        return result;
    }
};
