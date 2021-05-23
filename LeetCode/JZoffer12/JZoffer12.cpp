class Solution {
public:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int cursor) {
        if(i == -1 || i == board.size() || j == -1 || j == board[0].size() || board[i][j] != word[cursor]) {
            return false;
        }
        if(cursor == word.size()-1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '*';
        if(dfs(board, word, i-1, j, cursor+1) || dfs(board, word, i+1, j, cursor+1) || 
           dfs(board, word, i, j-1, cursor+1) || dfs(board, word, i, j+1, cursor+1)) {
            return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }    
        return false;
    }
};
