class Solution {
public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {

            if (candidates[i] > target)
                continue;

            current.push_back(candidates[i]);

            // Same index because the number can be reused
            backtrack(candidates,
                      target - candidates[i],
                      i,
                      current,
                      result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> result;
        vector<int> current;

        backtrack(candidates, target, 0, current, result);

        return result;
    }
};