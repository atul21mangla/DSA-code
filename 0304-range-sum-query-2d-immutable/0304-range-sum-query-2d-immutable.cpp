class NumMatrix {
public:
    vector<vector<int>>originalMatrix;
    vector<vector<int>>prefixMatrix;
    int n,m;

    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        prefixMatrix.assign(n,vector<int>(m,0));
        prefixMatrix[0][0] = matrix[0][0];

        for(int i=1;i<m;i++){
            prefixMatrix[0][i] = prefixMatrix[0][i-1] + matrix[0][i];
        }

        for(int i=1;i<n;i++){
            prefixMatrix[i][0] = prefixMatrix[i-1][0] + matrix[i][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                prefixMatrix[i][j] = prefixMatrix[i-1][j] + 
                prefixMatrix[i][j-1] + matrix[i][j] - prefixMatrix[i-1][j-1];
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = prefixMatrix[row2][col2];
        if(row1>0)res -= prefixMatrix[row1-1][col2];
        if(col1>0)res -= prefixMatrix[row2][col1-1];
        if(row1>0 && col1>0)res += prefixMatrix[row1-1][col1-1];

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */