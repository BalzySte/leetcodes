class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // implementing a simple DIY hashmap
        // each ASCII lowercase letter will be mapped onto a 0-25 number
        // an int[26] array will keep track of the available letters

        int letters[26] = {0};
        for (int i = 0; i < magazine.size(); ++i) {
            char l = magazine[i];
            letters[l - 'a'] += 1;
        }

        // consume the ransom letters
        for (int i = 0; i < ransomNote.size(); ++i) {
            char l = ransomNote[i];
            letters[l - 'a'] -= 1;
        }

        // verify no letter has a negative balance
        for (int i = 0; i < 26; ++i) {
            if (letters[i] < 0)
                return false;
        }
        return true;
    }
};
