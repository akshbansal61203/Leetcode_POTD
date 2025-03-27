class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int maj=NULL;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==maj){
                cnt++;
            }else if(cnt==0){
                maj=nums[i];
                cnt=1;
            }else cnt--;
        }
        int majcnt=0;
        for(auto it:nums){
            if(it==maj)majcnt++;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj){
                cnt++;
            }
            int n1=i+1;
            int n2=n-n1;
            int remain=majcnt-cnt;
            if(cnt*2>n1&&remain*2>n2)return i;
        }
        return -1;
    }
};
