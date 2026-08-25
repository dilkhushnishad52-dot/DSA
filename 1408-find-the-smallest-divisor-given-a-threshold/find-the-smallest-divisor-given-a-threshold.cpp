class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high  = *max_element(nums.begin(), nums.end());
    int ans = -1;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        double result = 0;
        for(int i=0; i<nums.size(); i++){
            result += ceil((double)nums[i]/mid);
        }
        if(result <= threshold){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    }
};