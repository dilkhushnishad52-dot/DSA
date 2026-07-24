class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int mxor = 0;
    for(int i = 0; i<nums.size(); i++){
        mxor = mxor ^ nums[i];
    }
    return mxor;
    }
};