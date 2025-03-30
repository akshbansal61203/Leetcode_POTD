class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26,0);
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
        }
        vector<int>result;
        int i=0,start=0,end=0;
        while(i<s.length()){
             end=max(end,last[s[i]-'a']);
            if(i==end){
                result.push_back(end-start+1);
                start=end+1;
            }
            //result.push_back(end-i+1);
            i++;
        }
        return result;
    }
};
