class Solution {
public:
    bool check(string&a,string&b){
        int diff=0;
       if(a.length()!=b.length())return 0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])diff++;
            if(diff>1)return 0;
        }
        return diff<=1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int n=words.size();
        vector<int>dp(n+1,1);
        vector<int>prev(n+1,-1);
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])&&groups[i]!=groups[j]&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
                if(dp[i]>dp[maxi])maxi=i;
            }
        }
        while(maxi!=-1){
            ans.push_back(words[maxi]);
            maxi=prev[maxi];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
