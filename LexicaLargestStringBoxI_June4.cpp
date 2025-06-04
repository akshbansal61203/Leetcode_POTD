class Solution {
public:
    int indextostart(string word,int n){
        int i=0;int j=1;
        while(j<n){
            if(word[i]<word[j]){
                i=j;
                j=i+1;
            }else if(word[i]>word[j]){
                j++;
            }else{
                int k=1;
                while(j+k<n&&(word[i+k]==word[j+k])){
                    k++;
                }
                if(j+k<n&& (word[i+k]<word[j+k])){
                    i=j;
                    j=i+1;
                }else{
                    j=j+k+1;
                }
            }
        }
        return i;
    }
    string answerString(string word, int numFriends) {
        int n=word.length();
        if(numFriends==1)return word;
        int ind=indextostart(word,n);
        return word.substr(ind,min(n-ind,n-(numFriends-1)));
    }
};
