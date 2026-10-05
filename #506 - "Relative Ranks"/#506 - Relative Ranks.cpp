class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<pair<int, int>> athletes;

        for (int i = 0; i < n; i++) {
            athletes.push_back({score[i], i});
        }

        sort(athletes.begin(), athletes.end(),
             [](auto& a, auto& b) {
                 return a.first > b.first;
             });

        vector<string> result(n);

        for (int i = 0; i < n; i++) {
            int originalIndex = athletes[i].second;

            if (i == 0)
                result[originalIndex] = "Gold Medal";
            else if (i == 1)
                result[originalIndex] = "Silver Medal";
            else if (i == 2)
                result[originalIndex] = "Bronze Medal";
            else
                result[originalIndex] = to_string(i + 1);
        }

        return result;
    }
};