int count(vector<int>& nums, int mid){
    int m = 1;
    int eleSum = 0;
    for(int i = 0; i<nums.size(); i++){
        if(eleSum + nums[i] <= mid){
            eleSum += nums[i];
        }
        else{
            m++;
            eleSum = nums[i];
        }
    }
    return m;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int i = 0; i<nums.size(); i++){
            high += nums[i];
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            int countele = count(nums, mid);
            if(countele > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};