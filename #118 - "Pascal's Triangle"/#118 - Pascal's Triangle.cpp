class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result;

        vector<int> prev = {1};
        result.push_back(prev);

        for (int row = 1; row < numRows; row++) {

            vector<int> curr;
            curr.push_back(1);

            for (int i = 0; i < prev.size() - 1; i++) {
                curr.push_back(prev[i] + prev[i + 1]);
            }

            curr.push_back(1);

            result.push_back(curr);
            prev = curr;
        }

        return result;
    }
};