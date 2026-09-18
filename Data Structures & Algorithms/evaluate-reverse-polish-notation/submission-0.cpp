class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        // define stack name 
        stack<int> st;
        for (string c: tokens)
        {
            if (isdigit(c[0]) || (c[0] == '-' && c.size() > 1)){
             st.push(stoi(c)); // stoi--makes a string into number
            }

            else
            {
               
                int b = st.top();
                st.pop();
                int a = st.top();
                 st.pop();

                if (c == "+")
                {
                    int ans = a + b;
                    st.push(ans);
                }

                else if (c == "-")
                {
                    int ans = a - b;
                    st.push(ans);
                }
                else if (c == "*")
                {
                    int ans = a * b;
                    st.push(ans);
                }

                else
                {
                    int ans = a / b;
                    st.push(ans);
                }
            }
        }

        return st.top();
    }
};
