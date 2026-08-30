class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        // Binary search on the smaller array
        if (n1 > n2)
            return findMedianSortedArrays(arr2, arr1);

        int low = 0;
        int high = n1;

        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while (low <= high) {

            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < n1)
                r1 = arr1[mid1];

            if (mid2 < n2)
                r2 = arr2[mid2];

            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];

            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Odd total length
                if (n % 2 == 1)
                    return max(l1, l2);

                // Even total length
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // We took too many elements from arr1
            else if (l1 > r2) {
                high = mid1 - 1;
            }

            // We need more elements from arr1
            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};