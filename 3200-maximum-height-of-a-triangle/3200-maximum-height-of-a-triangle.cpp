class Solution {
public:
    int func(int r, int b, char ch) {
        int c = 0;
        while (r > 0 || b > 0) {
            if (ch == 'b') {
                b -= (c + 1);
                ch = 'r';
            } else {
                r -= (c + 1);
                ch = 'b';
            }
            if (r >= 0 && b >= 0) {
                c++;
            }
        }
        return c;
    }

    int maxHeightOfTriangle(int r, int b) {
        int c1 = func(r, b, 'b');
        int c2 = func(r, b, 'r');
        return max(c1, c2);
    }
};