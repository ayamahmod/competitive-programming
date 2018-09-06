// Write a function that computes the length of the longest path of consecutive
// integers in a tree.
//
// A node in the tree has a value and a set of children nodes.
// A tree has no cycles and each node has exactly one parent.
// A path where each node has a value 1 greater than its parent is a path of
// consecutive integers (e.g. 1,2,3 not 1,3,5).
//
// A few things to clarify:
//
// - Integers are all positive
//
// - Integers appear only once in the tree
//
//
//
// Test Cases
//
// Note that there may be other valid answers.
//
// For the below tree, the length of the longest path is 2 (for path 1->2)
//
// 1 -> 2 -> 4
//
//    -> 3
//
// For the below tree, the max length is 4
//
// 5 -> 6
//
//    -> 7 -> 12
//
//           -> 8 -> 9 -> 15
//
//                          -> 10
//
