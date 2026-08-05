class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

         unordered_map<string, vector<string>> groups;

        // Process each word
        for (string s : strs) {

            // Create the key by sorting the word
            string key = s;
            sort(key.begin(), key.end());

            // Add the original word to its group
            groups[key].push_back(s);
        }

        // Convert map values into the required answer
        vector<vector<string>> result;

        for (auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
        
    
};
