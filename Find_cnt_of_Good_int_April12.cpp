class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int d=(n+1)/2;
        int start=pow(10,d-1);
        int end=pow(10,d)-1;
        unordered_set<string>st;
        for(int i=start;i<=end;i++){
            string left=to_string(i);
            string full="";
            if(n%2==0){
                string right=left;
                reverse(right.begin(),right.end());
                full=left+right;
            }else{
                string right=left.substr(0,d-1);
                reverse(right.begin(),right.end());
                full=left+right;
            }
            long long num=stoll(full);
            if(num%k)continue;
            sort(full.begin(),full.end());
            st.insert(full);
        }
        vector<long long>fact(11,1);
        for(int i=1;i<11;i++){
            fact[i]=fact[i-1]*i;
        }
        long long cnt=0;
        for(string s:st){
            vector<int>freq(10,0);
            int total=n;
            for(auto ch:s){
                freq[ch-'0']++;
            }
            int zeros=freq[0];
            int nonzero=n-zeros;
            long long permutation=(nonzero)*(fact[total-1]);
            for(int i=0;i<10;i++)permutation/=fact[freq[i]];
            cnt+=permutation;
        }
        return cnt;
    }
};
