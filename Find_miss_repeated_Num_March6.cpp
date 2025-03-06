class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>f(2500+1,0);
        int a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(f[grid[i][j]]>0){
                    a=grid[i][j];
                   // break;
                }
                f[grid[i][j]]++;
            }
        }
        for(int i=1;i<n*n+1;i++){
            if(f[i]==0){
                b=i;
            }
        }
        return {a,b};
    }
};
