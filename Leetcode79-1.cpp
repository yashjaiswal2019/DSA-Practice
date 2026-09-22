// Word search
// we will have to use Depth First Search for the every element of the metrix

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

bool helper(int &ROWS , int &COLS , vector<vector<char>> &board , string &word, int idx , int wordSize , int r , int c , set<vector<int>> &path);

bool exist(vector<vector<char>> &board, string &word);

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board , word);
    return 0;
}

bool helper(int &ROWS , int &COLS , vector<vector<char>> &board , string &word, int idx , int wordSize , int r , int c , set<vector<int>> &path) {
    // base case --> if we are on the last index is equal to word size we have found the word
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || (word[idx] != board[r][c]) ||(path.find({r, c}) != path.end())) return false;
    else if (idx == wordSize - 1) return true;

    // self work we can chek the element's left right top and bottom
    bool result = false;

    path.insert({r, c});
    if (helper(ROWS, COLS, board, word, idx + 1, wordSize, r + 1, c, path) ||
        helper(ROWS, COLS, board, word, idx + 1, wordSize, r - 1, c, path) ||
        helper(ROWS, COLS, board, word, idx + 1, wordSize, r, c + 1, path) ||
        helper(ROWS, COLS, board, word, idx + 1, wordSize, r, c - 1, path)) result = true;
        
    path.erase({r, c});
    return result;
}

bool exist(vector<vector<char>> &board, string &word)
{
    int ROWS = board.size() , COLS = board[0].size();
    set<vector<int>> path;
    int idx = 0 , wordSize = word.size();

    for (int r = 0 ; r < ROWS ; r++) {
        for (int c = 0 ; c < COLS ; c++) {
            if (helper(ROWS, COLS , board , word , idx , wordSize , r , c, path)) return true;
        }
    }
    return false;   // word doesn't exist in the matrix
}