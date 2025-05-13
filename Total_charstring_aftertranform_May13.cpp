const int MOD = 1e9 + 7;  // 1000000007
class Solution {
public:
    int lengthAfterTransformations(string& s, int t) {
        vector<int>mp(26,0);
        for(auto it:s)mp[it-'a']++;
        int ans=0;
        for(int i=1;i<=t;i++){
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                char ch=i+'a';
                int f=mp[i];
                if(ch!='z'){
                    temp[ch+1-'a']=(temp[ch+1-'a']+f)%MOD;
                }else{
                    temp['a'-'a']=(temp['a'-'a']+f)%MOD;
                    temp['b'-'a']=(temp['b'-'a']+f)%MOD;
                }
            }
            mp=move(temp);
        }
        for(auto it:mp){
            ans=(ans+it)%MOD;
        }
        return ans;
    }
};
