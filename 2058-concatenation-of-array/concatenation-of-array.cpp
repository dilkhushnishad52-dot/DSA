class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int a;
        int n = nums.size();
        vector<int> ans;
        int i = 0;
        while(i<=n){
            a = nums[i];
            ans.push_back(a);
            i++;
            if(i == n){
                i=0;
            }
            if(ans.size() == 2*n){
                break;
            }
        }
        return ans;
    }
};