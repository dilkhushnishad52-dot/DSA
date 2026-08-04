class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums;
        long long ans = 1;
        nums.push_back(ans);
        for(int i = 1; i<=rowIndex; i++){
            ans = ans * (rowIndex-i+1);
            ans = ans / (i);
            nums.push_back(ans);
        }
        return nums;
    }
};