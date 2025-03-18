class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int n=nums.size();
       int l=0,r=0;
       int subor=0,length=1;
       while(r<n){
       // subor|=nums[l];
        while((l<r)&&(subor&nums[r])){
            subor^=nums[l];
            l++;
        }
       length=max(length,r-l+1);
       subor|=nums[r];
        r++;
       } 
       return length;
    }
};
