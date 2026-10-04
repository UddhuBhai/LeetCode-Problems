class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Find how many words fit
            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int totalSpaces = maxWidth - lineLength;

            string line;

            // Last line or only one word
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1)
                        line += ' ';
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int spacesPerGap = totalSpaces / (wordCount - 1);
                int extraSpaces = totalSpaces % (wordCount - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1) {
                        int spaces = spacesPerGap;

                        // Extra spaces go to the left
                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};