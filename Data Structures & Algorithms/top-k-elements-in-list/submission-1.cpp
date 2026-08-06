class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums)
            freq[num]++;

        // Buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // Place elements into buckets
        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        // Traverse buckets from highest frequency
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    break;
        
        
            }

        }
        return ans;
    }
};
