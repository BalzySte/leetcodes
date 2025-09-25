class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len_nums = nums.size();
        int i = 0;
        int j = len_nums - 1;

        while(j >= 0 && nums[j] == val) {
            --j;
        }

        for (; i < j; ++i) {
        
            if (nums[i] == val) {
                nums[i] = nums[j];
                --j;

                while(j > 0 && nums[j] == val) {
                    --j;
                }
            }
        }

        return j + 1;
    }
};
