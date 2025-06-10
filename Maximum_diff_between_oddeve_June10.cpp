class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();
        int even=INT_MAX;
        int odd=0;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2){
                odd=max(odd,freq[i]);
            }
            else if(freq[i]%2==0&&freq[i]){
                even=min(even,freq[i]);
            }
        }
        return odd-even;
    }
};
