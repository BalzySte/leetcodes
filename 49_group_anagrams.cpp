using HashMap = array<unsigned int, 26>;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer = vector<vector<string>>();
        vector<HashMap> hashes = vector<HashMap>();

        // for each string
       for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            // compute the hash

            // HashMap* new_hash_ptr = new HashMap();
            // HashMap new_hash = *new_hash_ptr;
            HashMap new_hash = HashMap();
            computeHash(new_hash, str);

            // verify if the hash is already in the vector
            bool flag = false;
            for (int hash_idx = 0; hash_idx < hashes.size(); ++hash_idx) {
                HashMap& hash = hashes[hash_idx];
                
                if (compareHashes(new_hash, hash)) {
                    // add the string to existing group
                    answer[hash_idx].push_back(str);
                    flag = true;
                    break;
                }
            }

            if (flag)
                continue;
            
            // else add a new group
            // vector<string>* new_group_ptr = new vector<string>();
            // vector<string> new_group = *new_group_ptr;
            vector<string> new_group = vector<string>();
            new_group.push_back(str);
            answer.push_back(new_group);
            hashes.push_back(new_hash);
        }
        return answer;
    }

    void computeHash(HashMap& map, string& str) {
        map.fill(0);

        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            map[c - 'a'] += 1;
        }
    }

    bool compareHashes(HashMap h1, HashMap h2) {
        for (int i = 0; i < 26; ++i) {
            if (h1[i] != h2[i])
                return false;
        }
        return true;
    }

};
