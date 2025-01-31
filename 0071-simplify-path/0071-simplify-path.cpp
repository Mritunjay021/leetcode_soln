class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string current;
        
        path += "/";
        
        for (char c : path) {
            if (c == '/') {
                if (current == "..") {
                    if (!st.empty()) st.pop();
                } else if (current != "." && !current.empty()) {
                    st.push(current);
                }
                current = "";
            } else {
                current += c;
            }
        }
        
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        
        return result.empty() ? "/" : result;
    }
};