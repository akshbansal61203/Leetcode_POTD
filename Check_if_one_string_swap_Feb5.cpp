class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int i=0;
        int id=0,first=-1,second=-1;
        while(i<n){
            if(s1[i]!=s2[i]){
                id++;
                if(first==-1)first=i;
                second=i;
            }
            i++;
        }
        if(id==0)return true;
        if(id==2){
            if(s1[first]==s2[second]&&s1[second]==s2[first])return true;
        }
        return false;
    }
};
