class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Check if the complement already exists in the map
        if (numMap.find(complement) != numMap.end()) {
            // Since we iterate from left to right, numMap[complement] 
            // is guaranteed to be smaller than the current index i.
            return {numMap[complement], i};
        }
        
        // Store the index of the current number
        numMap[nums[i]] = i;
    }
    
    // Return an empty vector if no pair is found (guaranteed not to happen per problem constraints)
    return {};
        
    }
};
