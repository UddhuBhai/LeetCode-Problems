class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;
        int leftSize = (m + n + 1) / 2;

        while (low <= high) {

            int i = low + (high - low) / 2;
            int j = leftSize - i;

            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];

            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {

                if ((m + n) % 2 == 1)
                    return max(left1, left2);

                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            if (left1 > right2)
                high = i - 1;
            else
                low = i + 1;
        }

        return 0.0;
    }
};