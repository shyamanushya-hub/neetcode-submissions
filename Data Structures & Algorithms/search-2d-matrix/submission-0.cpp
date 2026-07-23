class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s = 0; int e = m-1;
        int c = (e+s) / 2;

        while(s <= e) {
            c = (e+s) / 2;

            if(target >= matrix[c][0] && target <= matrix[c][n-1]) {
                break;
            }
            else if(target < matrix[c][0])
                e = c -1;
            else
                s = c + 1;
        }

        if(s > e)
            return false;

        int row = c;

        s = 0; e = n-1;

        while(s <= e) {
            c = (e+s) / 2;
            if(target == matrix[row][c])
                return true;
            else if(target < matrix[row][c])
                e = c - 1;
            else
                s = c + 1;
        }

        return false;

    }
};
