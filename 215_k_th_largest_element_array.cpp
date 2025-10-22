class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int bins = 10000 * 2 + 1; 
        vector<unsigned int> hist(bins, 0);

        for (int num : nums)
            ++hist[num + 10000];
        
        int count = 0;
        int i = bins - 1;

        while (count < k) {
            int bin_count = hist[i];
            if (bin_count > 0)
                count += bin_count;
            --i;
        }

        return i + 1 - 10000;
    }
};

// NOTE: given the fairly narrow range of values (-10^4 <= nums[i] <= 10^4)
//       fastest solution is to implement a histogram.
//       There exist many different algorithms to this problem, each optimal
//       under specific circumstances.
//       An interesting exercise is to implement a max-heap (priority queue).
