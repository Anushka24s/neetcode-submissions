class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                char num = board[r][c];

                // Ignore empty cells
                if (num == '.')
                    continue;

                // Find the 3x3 box
                int box = (r / 3) * 3 + (c / 3);

                // Check for duplicate
                if (rows[r].count(num) ||
                    cols[c].count(num) ||
                    boxes[box].count(num)) {
                    return false;
                }

                // Add number to corresponding sets
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
    
};
