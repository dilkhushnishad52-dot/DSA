
class Solution {
public:

    // Largest Rectangle in Histogram (LC 84)
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {

            int curr = (i == n) ? 0 : heights[i];

            while(!st.empty() && heights[st.top()] > curr) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if(st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }

    // Maximal Rectangle (LC 85)
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);

        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            // Update histogram heights
            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }

            // Find largest rectangle for current row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
