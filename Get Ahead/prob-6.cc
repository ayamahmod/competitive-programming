// We look at car licence plates and try to find a word from the dictionary
// that includes all the letters from the licence plate.
// The shorter the word, the better. The licence plates start with
// two or three letters, then they are followed by 5 characters,
// from which at most 2 are letters, the rest are digits.
// Write code that will find the shortest words for 1000 licence plates.
// You are given a dictionary. e.g. for the licence plate "RT 123SO" the s
// hortest word would be "SORT", for "RC 10014": "CAR".
//
// A few things to clarify:
//
// - Keep duplicate letters
//
// - Ordering is irrelevant
//
// - Case is irrelevant
//
// - The dictionary is sorted lexicographically
//
// - The dictionary contains about 4 million entries
//
// Test Cases
//
// For the licence plate "RT 123SO" the shortest word would be "SORT"
//
// For "RC 10014", the shortest word is "CAR".
//
