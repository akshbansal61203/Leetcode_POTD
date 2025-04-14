class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i ++){
            for (int j = i+1; j < n; j++){
               if(a >= abs(arr[i]-arr[j])) {
                    for (int k = j+1; k < n; k++){
                    if (b >= abs(arr[k]-arr[j]) && c >= abs(arr[i]-arr[k])) ans++;
                    }
                }
            }
        }  
        return ans;      
    }
};
