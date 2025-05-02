class Solution {
public:
    string pushDominoes(string dominoes) {
         int n = dominoes.length();
        vector<int> closeR(n);
        vector<int> closeL(n);
        for(int i =n-1;i>=0;i--) {
            if(dominoes[i] == 'L')
                closeR[i]=i; 
            else if(dominoes[i] == '.')
                closeR[i] = i<n-1?closeR[i+1]:-1;
            else
                closeR[i]=-1;
        }
        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                closeL[i]=i; 
            else if(dominoes[i] == '.')
                closeL[i] = i > 0 ? closeL[i-1] : -1;
            else
                closeL[i] = -1;
        }
        string result(n, ' ');
        for(int i = 0; i<n; i++) {
            int distRightL = abs(i-closeR[i]); 
            int distLeftR  = abs(i-closeL[i]);  
            if(closeR[i] == closeL[i])
                result[i] = '.';
            else if(closeR[i] == -1)  
                result[i] = 'R';
            else if(closeL[i] == -1)  
                result[i] = 'L';
            else if(distLeftR == distRightL) 
                result[i] = '.';
            else
                result[i] = distRightL < distLeftR ? 'L': 'R'; 
        }
        return result;
    }
};
