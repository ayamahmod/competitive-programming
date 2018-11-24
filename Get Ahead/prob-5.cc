// Given a 4X4 grid of letters and a dictionary, find the longest word from the
// dictionary that can be formed in the grid.
// The rules for forming a word are:
// Start at any position on the board
// Move in any of the up to 8 directions to choose another letter
//  Repeat
// Words must be at least 3 characters long
// You cannot reuse a letter in a given position in the same word
// You are given a dictionary, with helper functions like isWord() to check
// if a word is valid and isPrefix() to check if a string is a prefix of some valid word.
// Test Cases
// Note that there may be other valid answers.
// For the grid below, the longest word is EMBOIL
// F X I E
// A M L O
// E W B X
// A S T U
// For the grid below, the longest word is KNIFE
// A B C D
// E F G H
// I J K L
// M N O P
#define GRID_SIZE 4

void DFS(const vector<vector<char> >& grid, int i, int j,
  vector<vector<bool> >& visited, string currWord, string& longestWord) {
  if(visited[i][j]) return;
  visited[i][j] = true;
  currWord += grid[i][j];
  if(isWord(currWord) && longestWord.size() < currWord.size()) longestWord = currWord; 
  if(isPrefix(currWord)) {
    int di[] = [-1, -1, -1, 0, 0, 1, 1, 1]
    int dj[] = [-1, 0, 1, -1, 1, -1, 0, 1]
    for(int k = 0; k < 8; ++k){
      int idi = i+di[k], jdj = j+dj[k];
      if(idi >= 0 && idi < GRID_SIZE && jdj >= 0 && jdj < GRID_SIZE)
        DFS(grid, idi, jdj, visited, currWord, longestWord);
    }
  }
}

string longestWord(const vector<vector<char> >& grid) {
  int size = GRID_SIZE;
  string longestWord = "";
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      vector<vector<bool> > visited(size, vector<bool>(size, false));
      DFS(grid, i, j, visited, "", longestWord);
    }
  }
}
