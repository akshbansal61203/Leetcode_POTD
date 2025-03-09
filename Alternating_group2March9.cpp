class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int maxLen=1,count=0;
        for(int i=1;i<n-1+k;i++){
            if(colors[i%n]!=colors[(i-1+n)%n])maxLen++;
            else maxLen=1;
            if(maxLen>=k)count++;
        }
        return count;
    }
};
