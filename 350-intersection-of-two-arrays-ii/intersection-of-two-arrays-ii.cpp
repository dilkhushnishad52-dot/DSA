class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mm;
        vector<int> ans;

        for(int x : nums1){
            mm[x]++;
        }
        for(int x : nums2){
            if(mm[x] > 0){
                ans.push_back(x);
                mm[x]--;
            }
        }
        return ans;
    }
};