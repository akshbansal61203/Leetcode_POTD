class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(auto el:words){
            string rev=el;
            swap(rev[0],rev[1]);
            if(mp[rev]>0){
                ans+=4;
                mp[rev]--;
            }else{
                mp[el]++;
            }
        }
        for(auto el:mp){
            if(el.first[0]==el.first[1]&&el.second>0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};
