class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums);

            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);

        backtrack(nums);

        return result;
    }
};