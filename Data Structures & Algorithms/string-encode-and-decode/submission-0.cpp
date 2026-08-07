class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";

        for (string s : strs)
        {
            encoded += to_string(s.length()) + "#" + s;
        }
        
    return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
    int i = 0;

    while (i < s.length()) {

        // Find the '#'
        int j = i;
        while (s[j] != '#') {
            j++;
        }

        // Length of the next word
        int len = stoi(s.substr(i, j - i));

        // Move past '#'
        j++;

        // Extract the word
        result.push_back(s.substr(j, len));

        // Move to the next encoded word
        i = j + len;
    }

    return result;
    }
};
