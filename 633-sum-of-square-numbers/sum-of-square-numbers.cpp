class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = sqrt(c);
        while(low <= high){
            if(((long long)low * low + (long long)high * high) == c){
                return true;
            }
            else if(((long long)low * low + (long long)high * high) > c){
                high --;
            }
            else{
                low++;
            }
        }
        return false;
    }
};