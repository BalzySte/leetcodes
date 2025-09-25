class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum;
        vector<int> answer = vector<int>(2);
        int i = 0, j = numbers.size() - 1, j_max = j;

        for (int i = 0; i < j_max; ++i) {

            while (j > i) {
                sum = numbers[i] + numbers[j];
                if (sum > target) {
                    j -= 1;
                    continue;
                }
                break;
            }

            if (sum == target) {
                answer[0] = i + 1;
                answer[1] = j + 1;
                break;
            }

            j_max = j + 1;
        }

        return answer; 
    }
};
