class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        stack<char> st;
        for(auto c: s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if(st.empty())
                    return false;
                auto t = st.top();
                st.pop();
                if(m[c] != t) 
                    return false;
            }
        }

        if(st.empty())
            return true;
        else
            return false;
    }
};
