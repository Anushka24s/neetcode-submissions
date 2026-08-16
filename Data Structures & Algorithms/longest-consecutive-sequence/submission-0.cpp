class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st;

       for (int num : nums){
            st.insert(num);
       } 

       int longest=0;
       for (int num:st)
       {
        if(st.find(num-1)==st.end())
        {
            int currentNum = num;
            int currentLenght =1;
        

        while(st.find(currentNum + 1)!=st.end())
        {
            currentNum++;
            currentLenght++;
        }
        longest = max(longest , currentLenght);
       }

      
    }
         return longest;
    }

};
