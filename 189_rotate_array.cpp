class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();

        // if len <= k
        // ensure k is always < len
        if (len <= k) {
            k = k % len;
        }

        // do nothing if k = 0
        if (k == 0) {
            return;
        }

        int a = len, b = k, mcd;

        while(b != 0) {
            mcd = b;
            b = a % b;
            a = mcd;
        }

        // there are an mcd number of cycles
        for (int i = 0; i < mcd; ++i){
            int start = len - 1 - i;
            int temp = nums[start];

            // replace items in the cycle until the start is reached
            int j = start - k;
            while (j != start) {
                nums[(j + k) % len] = nums[j];
                j = (j - k + len) % len;
            }

            nums[(j + k) % len] = temp;
        }
    }
};
