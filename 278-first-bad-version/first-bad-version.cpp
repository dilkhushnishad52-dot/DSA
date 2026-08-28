// The API isBadVersion is provided by LeetCode.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            bool bad = isBadVersion(mid);

            if (bad) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};