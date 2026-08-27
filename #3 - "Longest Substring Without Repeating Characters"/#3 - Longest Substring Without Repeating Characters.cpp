class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        
        for (int i = 0; i < 256; i++) {
            last[i] = -1;
        }

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            unsigned char c = s[right];

            if (last[c] >= left) {
                left = last[c] + 1;
            }

            last[c] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};