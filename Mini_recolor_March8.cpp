class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 0;
        int r = 0;
        int ops = k;
        int W = 0;
        while(r < n) {
            if(blocks[r] == 'W') {
                W++;
            }
            if(r - l + 1 == k) {
                ops = min(ops, W);

                if(blocks[l] == 'W') {
                    W--;
                }
                l++;
            }
            r++;
        }

        return ops;
    }
};
