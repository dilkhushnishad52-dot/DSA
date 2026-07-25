class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int b;
        for(int i = 0; i<nums.size(); i++){
            b = nums[nums[i]];
            ans.push_back(b);
        }
        return ans;
    }
};