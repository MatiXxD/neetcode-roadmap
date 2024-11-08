bool isValidSudoku(vector<vector<char>> &board) {
  std::vector<std::unordered_set<char>> rows(9);
  std::vector<std::unordered_set<char>> cols(9);
  std::vector<std::unordered_set<char>> boxs(9);

  for (size_t i = 0; i != board.size(); ++i) {
    for (size_t j = 0; j != board.size(); ++j) {
      if (board[i][j] == '.') {
        continue;
      }

      if (rows[i].contains(board[i][j])) {
        return false;
      } else {
        rows[i].insert(board[i][j]);
      }

      if (cols[j].contains(board[i][j])) {
        return false;
      } else {
        cols[j].insert(board[i][j]);
      }

      if (boxs[3 * (i / 3) + j / 3].contains(board[i][j])) {
        return false;
      } else {
        boxs[3 * (i / 3) + j / 3].insert(board[i][j]);
      }
    }
  }

  return true;
}
