class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // hashmaps for rows, cols, and squares

        // the squares formula was inspired by the hint but the rest is all mine

        std::unordered_map<int, unordered_set<char>> rows;
        std::unordered_map<int, unordered_set<char>> cols;
        std::unordered_map<int, unordered_set<char>> squares;

        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[r].size(); c++)
            {
                // rows are represented by r
                // cols are represented by c
                // squares are represented by (r/3) * 3 + (c/3)
                if (board[r][c] == '.')
                    continue;

                int s = (r / 3) * 3 + (c / 3);

                if (rows[r].count(board[r][c]))
                {
                    return false;
                }
                rows[r].insert(board[r][c]);

                if (cols[c].count(board[r][c]))
                {
                    return false;
                }
                cols[c].insert(board[r][c]);

                if (squares[s].count(board[r][c]))
                {
                    return false;
                }
                squares[s].insert(board[r][c]);
            }
        }

        return true;
    }
};
