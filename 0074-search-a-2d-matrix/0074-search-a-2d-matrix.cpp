// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int t)
//     {
//         // int m = mt.size();
//         // int n = mt[0].size();

//         // int l = 0, u = m - 1, c = -1;

//         // while (l <= u)
//         // {
//         //     int md = (l + u) / 2;
//         //     if (mt[md][0] == t)
//         //         return true;
//         //     else if (mt[md][0] > t)
//         //         u = md - 1;
//         //     else
//         //     {
//         //         c = md;
//         //         l = md + 1;
//         //     }
//         // }

//         // if (c == -1)
//         //     return false;

//         // l = 0;
//         // u = n - 1;

//         // while (l <= u)
//         // {
//         //     int md = (l + u) / 2;
//         //     if (mt[c][md] == t)
//         //         return true;
//         //     else if (mt[c][md] > t)
//         //         u = md - 1;
//         //     else
//         //         l = md + 1;
//         // }

//         // return false;
//         int m = matrix.length, n = matrix[0].length;
// int start = 0, end = m * n - 1;

// while(start <= end) {
// int mid = start + (end - start) / 2;
// int row = mid / n, col = mid % n;
// if(matrix[row][col] == target) return true;
// else if(matrix[row][col] < target) start = mid + 1;
// else end = mid - 1;
// }
// return false;
//     }
// };


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();         // Number of rows
        int n = matrix[0].size();      // Number of columns
        int start = 0, end = m * n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / n;         // Determine the row index
            int col = mid % n;         // Determine the column index

            if (matrix[row][col] == target) 
                return true;           // Target found
            else if (matrix[row][col] < target) 
                start = mid + 1;       // Move right
            else 
                end = mid - 1;         // Move left
        }

        return false;                  // Target not found
    }
};
