class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = n - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (target >= matrix[mid][0] &&
                target <= matrix[mid][m - 1]) {

                int l = 0, r = m - 1;

                while (l <= r) {
                    int midCol = l + (r - l) / 2;

                    if (matrix[mid][midCol] == target) {
                        return true;
                    }
                    else if (matrix[mid][midCol] < target) {
                        l = midCol + 1;
                    }
                    else {
                        r = midCol - 1;
                    }
                }

                return false;
            }
            else if (target < matrix[mid][0]) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return false;
    }
};