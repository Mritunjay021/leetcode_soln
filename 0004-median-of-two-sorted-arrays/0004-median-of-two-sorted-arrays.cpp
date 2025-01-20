class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) 
    {
        int m = n1.size(), n = n2.size();
        int p1 = 0, p2 = 0;
        int current = 0, previous = 0;
        int totalSize = m + n;
        int md = totalSize / 2;

        for (int i = 0; i <= md; i++) {
            previous = current;
            if (p1 < m && (p2 >= n || n1[p1] <= n2[p2])) {
                current = n1[p1++];
            } else {
                current = n2[p2++];
            }
        }

        if (totalSize % 2 == 0) {
            return (current + previous) / 2.0;
        } else {
            return current;
        }
    }
};
