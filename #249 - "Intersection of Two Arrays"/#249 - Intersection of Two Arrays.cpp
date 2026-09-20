class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> result;

        for (int num : nums1)
            st.insert(num);

        for (int num : nums2) {
            if (st.count(num)) {
                result.push_back(num);
                st.erase(num);
            }
        }

        return result;
    }
};