class Solution {
public:
    string robotWithString(string s) {
        string t="",p="";
        int n=s.length();
        vector<char>mini(n);
        mini[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(s[i],mini[i+1]);
        }
        for(int i=0;i<n;i++){
            t+=s[i];
           char minim=(i+1<n)?mini[i+1]:s[i];
           while(!t.empty()&&t.back()<=minim){
                p+=t.back();
                t.pop_back();
           }
        }
        while(!t.empty()){
             p+=t.back();
                t.pop_back();
        }
        return p;
    }
};
