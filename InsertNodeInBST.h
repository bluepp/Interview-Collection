/*
  bluepp
  2014-12-22
  May the force be with me!
  
  Insert a node to a BST tree
  
  Binary search tree. Adding a value

*/

/*http://www.algolist.net/Data_structures/Binary_search_tree/Insertion */
bool BinarySearchTree::add(int value) {
      if (root == NULL) {
            root = new BSTNode(value);
            return true;
      } else
            return root->add(value);
}
 
bool BSTNode::add(int value) {
      if (value == this->value)
            return false;
      else if (value < this->value) {
            if (left == NULL) {
                  left = new BSTNode(value);
                  return true;
            } else
                  return left->add(value);
      } else if (value > this->value) {
            if (right == NULL) {
                  right = new BSTNode(value);
                  return true;
            } else
                  return right->add(value);
      }
      return false;
}
  
  
  TreeNode * add(TreeNode *root, int val)
  {
    if (!root) 
    {
      TreeNode *root = new TreeNode (val);
      return root;
    }
    
    if (val == root->val) return ?
    if (val < root->val) 
    { 
      root->left = add(root->left, val);
    }
    else
    {
      root->right = add(root->right, val);
    }
    
    return root;
  }
  
