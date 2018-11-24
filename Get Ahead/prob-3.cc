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
//   -> 3
//
// For the below tree, the max length is 4
//
// 5 -> 6
//   -> 7 -> 12
//        -> 8 -> 9 -> 15
//                  -> 10
//

int longestPath(Node* r) {
  int max_len = 0;
  longestPath(r, max_len, 0,  NULL);
  return len;
}

void longestPath(Node* node, int& max_len, int run_len, Node* r) {
  if(node == NULL) {
    max_len = max(max_len, run_len);
    return;
  }
  if(r != NULL && (r->val+1) == node->val) {
    ++run_len;
  } else {
    max_len = max(max_len, run_len);
    run_len = 1;
  }
  longestPath(node->left, max_len, run_len, node);
  longestPath(node->right, max_len, run_len, node);
}
