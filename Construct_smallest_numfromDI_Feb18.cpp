class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char>st;
        int count=1;
        string ans="";
        st.push(count+'0');
        int i=0;
        while(i<pattern.size()){
            if(pattern[i]=='I'){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            count++;
            st.push(count+'0');
            i++;
        }
        while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            return ans;
    }
};
