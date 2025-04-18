class Solution {
public:
    vector<pair<int ,int>>freq_map(string &s){
        vector<pair<int,int>>mp;
        int cnt=1;
        for(int i=0;i<s.length();i++){
            while(i<s.length()&&s[i]==s[i+1]){
                cnt++;
                i++;
            }
            mp.push_back({s[i]-'0',cnt});
            cnt=1;
        }
        return mp;
    }
    string stringcreate(vector<pair<int ,int>>&mp){
        string t="";
        for(auto&[a,b]:mp){
            t+=b+'0';
            t+=a+'0';
        }
        return t;
    }
    string countAndSay(int n) {
        if(n==1)return "1";
        string s="1";
        for(int i=0;i<n-1;i++){
           vector<pair<int ,int>> mp=freq_map(s);
             s=stringcreate(mp);
             cout<<s<<endl;
        }
        return s;
    }
};
