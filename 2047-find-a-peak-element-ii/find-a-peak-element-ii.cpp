int maxEle(vector<vector<int>>& matrix, int n, int m, int col){
    int maxValue = -1;
    int index = -1;
    for(int i = 0; i<n; i++){
        if(matrix[i][col] > maxValue){
            maxValue = matrix[i][col];
            index = i;
        }
    }
    return index;
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = maxEle(matrix,n,m,mid);
        int left = mid - 1 >= 0 ? matrix[row][mid - 1] : -1;
        int right = mid + 1 < m ? matrix[row][mid + 1] : -1;
        if(matrix[row][mid] > left && matrix[row][mid] > right){
            return {row, mid};
        }
        else if(matrix[row][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1,-1};
    }
};