class Solution {
public:
    int count(int curr,int nxt,int n){
        int cnt=0;
        while(curr<=n){
            cnt+=nxt-curr;
            curr*=10;
            nxt*=10;
            nxt=min(nxt,n+1);
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k-=1;
        while(k>0){
            int cnt=count(curr,curr+1,n);
            if(cnt<=k){
                curr++;
                k-=cnt;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
