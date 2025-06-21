class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>f(26,0);
        for(auto el:word){
            f[el-'a']++;
        }
        int mini=INT_MAX;
        for(int i=0;i<26;i++){
            int del=0;
            for(int j=0;j<26;j++){
                if(i==j)continue;
                else if(f[j]-f[i]>k){
                    del+=f[j]-f[i]-k;
                }else if(f[j]<f[i])del+=f[j];
            }
            mini=min(del,mini);
        }
        return mini;
    }
};
