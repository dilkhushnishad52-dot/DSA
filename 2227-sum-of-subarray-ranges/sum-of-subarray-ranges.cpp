
class Solution {
public:

    // Previous Smaller Element
    vector<int> findPSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    // Next Smaller Element
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    // Previous Greater Element
    vector<int> findPGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pge;
    }

    // Next Greater Element
    vector<int> findNGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    long long subArrayMin(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse = findPSE(nums);
        vector<int> nse = findNSE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            sum += left * right * nums[i];
        }

        return sum;
    }

    long long subArrayMax(vector<int>& nums) {
        int n = nums.size();

        vector<int> pge = findPGE(nums);
        vector<int> nge = findNGE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;

            sum += left * right * nums[i];
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        return subArrayMax(nums) - subArrayMin(nums);
    }
};
