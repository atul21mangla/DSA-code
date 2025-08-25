class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int r = matrix.size();
        // int c = matrix[0].size();
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(matrix[i][j]==target)return true;
        //     }
        // }
        // return false;

        int r = matrix.size();
        int c = matrix[0].size();

        int low = 0 , high = r-1;
        int row = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]>target)high = mid-1;
            else {
                row = mid;
                low = mid+1;
            }
        }
        if(row==-1)return false;

        cout<<row;
        low = 0 , high = c-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid]>target)high = mid-1;
            else {
                low = mid+1;
            }
        }
        return false;
    }
};