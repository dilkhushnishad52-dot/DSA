class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> myset(nums1.begin(), nums1.end());
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            int x = nums2[i];
            if(myset.count(x)){
                ans.push_back(x);
                myset.erase(x);
            }
        }
        return ans;
    }
};