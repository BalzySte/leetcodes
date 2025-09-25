class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int longest_count = 0;

    unordered_set nums_set(nums.begin(), nums.end());

    // iterate on every number in the set
    for (int num: nums_set) {
        // if the number is the first of a sequence
        // then measure the legth of the sequence
        // else ignore it
        if (nums_set.find(num - 1) == nums_set.end()) {
            int seq_count = 1;

            while (nums_set.find(num + seq_count) != nums_set.end()) {
                seq_count += 1;
            }

            longest_count = max(longest_count, seq_count);
        }
    }

    return longest_count;
    }
};
