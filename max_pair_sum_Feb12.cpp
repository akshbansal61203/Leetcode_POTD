//approach 1
//O(nlogn)
class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            n=n/10;
            sum+=rem;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mp;
        for(int i=0;i<nums.size();i++){
            int sum=digitSum(nums[i]);
            mp[sum].push(nums[i]);
        }
        int maxi=-1;
        for(auto it:mp){
            int sum=0;
            if(it.second.size()>=2){
                sum+=it.second.top();
                it.second.pop();
                sum+=it.second.top();
                it.second.pop();
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};

//Approach-2
//optimal
//Approach-2 (Optimal array as Map of constant size)
//T.C : O(n*m), m = number of digits
//S.C : O(1)
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        int mp[82] = {0};

        for(int i = 0; i < n; i++) {
            int digitSum = getDigitSum(nums[i]);

            if(mp[digitSum] > 0) {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }

        return result;
    }
};
