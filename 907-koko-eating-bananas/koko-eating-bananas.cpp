long long calTotalHours(vector<int> &nums, int hourly){
    long long totalH = 0;
    for(int i = 0; i<nums.size(); i++){
        totalH += (nums[i] + hourly - 1) / hourly; 
    }
    return totalH;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    
    while(low <= high){
        int mid = low + (high - low)/2;
        long long totalH = calTotalHours(nums, mid);
        if(totalH <= h){
            high = mid-1;
        } 
        else{
            low = mid+1;
        }
    }
    return low;
    }
};