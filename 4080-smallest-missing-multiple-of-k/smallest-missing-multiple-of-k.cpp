class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        for (int num : nums) {
            mapp[num]++; 
        }
        int multiple = k;
        while(true){
            if(mapp.find(multiple) == mapp.end()){
                return multiple;
            }
            multiple += k;
        }
    }
};