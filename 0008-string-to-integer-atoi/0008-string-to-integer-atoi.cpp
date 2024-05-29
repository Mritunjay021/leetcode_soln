
class Solution {
public:
    int sign = 1;
    long createAtoi(string& s, int i, long re) {
        //cout << re << " ";
        if (re * sign >= INT_MAX)
            return INT_MAX;
        if (re * sign <= INT_MIN)
            return INT_MIN;
        if (s[i] < '0' || s[i] > '9')
            return re;
        else
            return createAtoi(s, i + 1, re * 10 + (s[i] - '0'));
    }

    long myAtoi(string s) {
        long re = 0;
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == ' ')
                continue;
            break;
        }
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-')
                sign = -1;
            return createAtoi(s, i + 1, re) * (s[i] == '-' ? -1 : 1);
        } else
            return createAtoi(s, i, re);
    }
};