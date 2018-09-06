// Given a 4X4 grid of letters and a dictionary, find the longest word from the dictionary that can be formed in the grid.
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
// For the grid below, the longest word is FAME
// F X  I E
// A M L  O
// E W B X
// A S T  U
// For the grid below, the ongest word is EMBOIL
// A  B C D
// E  F G H
// I   J K L
// M N O P
