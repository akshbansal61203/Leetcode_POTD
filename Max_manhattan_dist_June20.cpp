class Solution {
public:
    int maxi=0;
    void dist(string s,int k,char y,char x){
        int dis=0;
        for(auto ch:s){
            if(ch==x||ch==y)dis++;
            else if(k){
                    dis++;
                    k--;
                
            }else dis--;
             maxi=max(maxi,dis);
        }
       
    }
    int maxDistance(string s, int k) {
        dist(s,k,'N','W');
        dist(s,k,'N','E');
        dist(s,k,'S','E');
        dist(s,k,'S','W');
        return maxi;
    }
};
