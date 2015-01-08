/*
  bluepp
  2015-01-07
  May the force be with me!
  
http://www.mitbbs.com/article_t/JobHunting/32743051.html  
  一棵树。如果根到自己的路上没有比自己更大的节点，那么这个点就是可见的。

输入树的根节点，返回可见节点个数

比如
           5
         /     \
     3           10
   / \            /
20   21     1

返回4
*/

/* recursion */
int uncover(TreeNode *root)
{
	if (!root) return 0;
	
	return _uncover(root, root->val);
}

int _uncover(TreeNode *root, int val)
{
	if (!root) return 0;
	
	int newval = max(val, root->val);
	
	if (root->val >= newval)
	{
		return _uncover(root->left, newval)+_uncover(root->right, newval)+1;
	}
	else
	{
		return _uncover(root->left, newval)+_uncover(root->right, newval);
	}
	
}

/* iterative, with stack */
