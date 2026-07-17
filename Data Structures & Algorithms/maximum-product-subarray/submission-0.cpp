class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxend = nums[0];
        int minend = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxend, minend);
            }
           maxend=max(nums[i],maxend*nums[i]);
           minend=min(nums[i],minend*nums[i]);
           ans=max(ans,maxend);
        }
        return ans;
    }
};
