class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> seen;
        seen.reserve(board.size());
        for (const auto& row : board) {
            for (const auto c : row) {
                if (c == '.') continue;
                if (seen.contains(c)) return false;
                seen.insert(c);
            }
            seen.clear();
        }
        for (std::size_t column = 0; column < board[0].size(); ++column) {
            for (std::size_t row = 0; row < board.size(); ++row) {
                const char c = board[row][column];
                if (c == '.') continue;
                if (seen.contains(c)) return false;
                seen.insert(c);
            }
            seen.clear();
        }
        for (std::size_t row = 0; row < board.size(); row += 3) {
            for (std::size_t column = 0; column < board[0].size(); column += 3) {
                for (std::size_t currRow = row; currRow < row+3; ++currRow) {
                    for (std::size_t currColumn = column; currColumn < column+3; ++currColumn) {
                        const char c = board[currRow][currColumn];
                        if (c == '.') continue;
                        if (seen.contains(c)) return false;
                        seen.insert(c);
                    }
                }
                seen.clear();
            }
        }
        return true;
    }
};
