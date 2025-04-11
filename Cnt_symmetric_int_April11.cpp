class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++){
            if(10<i&&i<=99&&i%11==0)c++;
            else if(i>1000&&i<=9999){
                int first=i/1000;
                int second=(i/100)%10;
                int third=(i/10)%10;
                int fourth=i%10;
                if(first+second==third+fourth)c++;
            }
        }
        return c;
    }
};
