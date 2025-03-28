class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int sign = 1; // +ve
        int num = 0; // temp storage

        for (auto ch : s) {
            if ('0' <= ch && ch <= '9') {
                num = num*10 + (ch - '0');
            }
            else if (ch == '+') {
                result += sign*num;
                sign = 1;
                num = 0;
            }
            else if (ch == '-') {
                result += sign*num;
                sign = -1;
                num = 0;
            }
            else if (ch == '(') {
                // push the curr result ans sign onto stack
                st.push(result);
                st.push(sign); // ab tak ka expression ka ans store kr liya hia
                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                result += sign*num;
                // pop the sign first then result jo push hua tha
                sign = st.top();
                st.pop();
                result *= sign;
                result += st.top();
                st.pop();
                num = 0;
            }
        }

        result += sign*num; // add the last number to the result
        return result;
    }
};