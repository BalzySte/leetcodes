class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> answer;

        // for each string
        for (auto& str: strs) {
            string str_key = str;
            // when length of strings is small (typical word length)
            // sorting will be faster compared to other methods
            // such as building freq historgrams and comparing them
            sort(str_key.begin(), str_key.end());
            
            anagrams[str_key].push_back(str);
        }

        answer.reserve(anagrams.size());
        for (auto& [k, v] : anagrams) {
            answer.push_back(v);
        }

        return answer;
    }
};
