class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (target <= matrix[i][m - 1]) {
                int j = 0;
                int k = m - 1;

                while (j <= k) {
                    int mid = j + (k - j) / 2;

                    if (matrix[i][mid] == target) {
                        return true;
                    }
                    else if (target > matrix[i][mid]) {
                        j = mid + 1;
                    }
                    else {
                        k = mid - 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};