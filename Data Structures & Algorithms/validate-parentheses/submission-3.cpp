class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(!st.empty()) {
                    char topVal = st.top();
                    if((s[i] == '}' && topVal != '{') || (s[i] == ']' && topVal != '[') || (s[i] == ')' && topVal != '('))
                        return false;
                    st.pop();    
                }
                else
                    return false;
            }   
        }
        return st.empty();
    }
};
