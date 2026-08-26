class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char current = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != current) {
                    return prefix;
                }
            }

            prefix += current;
        }

        return prefix;
    }
};