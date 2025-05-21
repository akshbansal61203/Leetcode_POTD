class Solution {
public:
void matri(vector<vector<int>>& matrix,int i,int j,int n,int m){
    for(int p=0;p<n;p++){//row
        matrix[p][j]=0;
    }
    for(int k=0;k<m;k++){//col
        matrix[i][k]=0;
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vec.push_back({i,j});
                }
            }
        }
        for(auto it:vec){
            int r=it.first;
            int c=it.second;
            matri(matrix,r,c,n,m);
        }
        return;
    }
};
