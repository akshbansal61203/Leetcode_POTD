class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n=s.length();
        int x=n%k;
        if(x) n=n-n%k;
        int i=0;
        while(i<n){
            string t=s.substr(i,k);
            ans.push_back(t);
            i+=k;
        }
        if(i<s.length()){
            ans.push_back(s.substr(i,s.length()-i));
            string t=ans.back();
            t+=string(k-(s.length()-i),fill);
            ans.pop_back();
            ans.push_back(t);
        }
        return ans;
    }
};
