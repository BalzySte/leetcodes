class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_len = nums.size();
        int j = 2;

        if (nums_len <= 2) {
            return nums_len;
        }

        for (int i = 2; i < nums_len; ++i) {
            if (nums[i] == nums[j - 1] && nums[i] == nums[j - 2]) {
                continue;
            }

            nums[j] = nums[i];
            ++j;
        }
        
        return j;
    }
};
