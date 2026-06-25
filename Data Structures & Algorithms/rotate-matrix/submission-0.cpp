class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //swap among rows
        for(int i=0;i<n;i++){
            for(int j=0;j<=(n-1)/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
