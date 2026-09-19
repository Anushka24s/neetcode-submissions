class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        int i;
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()] )
        {
            int previousDay = st.top();
            st.pop();

            result[previousDay] = i - previousDay;
           
        }
         st.push(i);
        }
        return result;
    }
};
