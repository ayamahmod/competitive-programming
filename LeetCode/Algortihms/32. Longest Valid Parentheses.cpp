class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(!st.empty())
                    len=max(len, i-st.top());

                else    st.push(i);
            }
        }
        return len;
    }
};
