class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int row = -1;
        while(l <= r){
            cout << l << " " << r << endl;
            int mid = ((r - l) / 2) + l;
            if(matrix[mid][0] > target){
                r = mid - 1;
            }
            else if(matrix[mid][matrix[mid].size() - 1] < target){
                l = mid + 1;
            }
            else{
                row = mid;
                break;
            }

            cout << l << " " << r << endl << endl;
        }
        cout << row << endl;
        if(row == -1){
            return false;
        }
        l = 0; r = matrix[row].size() - 1;
        while(l <= r){
            int mid = ((r - l) / 2) + l;
            if(matrix[row][mid] < target){
                l = mid + 1;
            }
            else if(matrix[row][mid] > target){
                r = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};