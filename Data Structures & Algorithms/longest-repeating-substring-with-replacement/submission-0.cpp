class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> f;
        int low = 0;
        int maxFreq = 0;
        int res = INT_MIN;

        for (int high = 0; high < s.size(); high++) {
            f[s[high]]++;
            maxFreq = max(maxFreq, f[s[high]]);

                while ((high - low + 1) - maxFreq > k) {
                f[s[low]]--;

                low++;
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};
