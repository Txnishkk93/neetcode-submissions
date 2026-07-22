class Solution {
   public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        int n = s.size();
        for (char c : s) {
            st.push(c);
        }
        for (int i = 0; i < n; i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};