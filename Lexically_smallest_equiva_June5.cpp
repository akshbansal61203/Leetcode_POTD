class Solution {
public:
    char dfs(char ch,unordered_map<char,vector<char>>&mp,vector<bool>&vis){
        vis[ch-'a']=true;
        char minchar=ch;
        for(auto it:mp[ch]){
            if(!vis[it-'a']){
                minchar=min(minchar,dfs(it,mp,vis));
            }
        }
        return minchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        int m=baseStr.length();
        unordered_map<char,vector<char>>mp;
        for(int i=0;i<n;i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        string res;
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            vector<bool>visited(26,0);
            char minch=dfs(ch,mp,visited);
            res.push_back(minch);
        }
        return res;
    }
};
