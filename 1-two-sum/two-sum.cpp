class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int need = target - first;
            if(m.find(need) != m.end()){
                return {m[need],i};
            }
            m[first] = i;
        }
        return { };
    }
};