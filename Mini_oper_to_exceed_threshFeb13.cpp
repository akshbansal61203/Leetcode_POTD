class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());
        int c=0;
        while(!pq.empty()&&pq.top()<k){
            long small=pq.top();
            pq.pop();
            long ssmall=pq.top();
            pq.pop();
            long ele=small*2+ssmall;
            pq.push(ele);
            c++;
        }
        return c;
    }
};
