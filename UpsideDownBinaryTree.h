/*
  2014-09-22
  bluepp
  May the force be with me

http://www.mitbbs.com/article_t1/JobHunting/32775405_0_1.html

Given a binary tree where all the right nodes are leaf nodes, flip it 
upside down
and turn it into a tree with left leaf nodes.


https://github.com/yxjiang/algorithms/blob/master/src/main/java/algorithm/linkedin/UpsideDownBinaryTree.java

*/



    TreeNode dfs(TreeNode node, TreeNode parent){
        if(node==null) return null;
        TreeNode left_res = dfs(node.left,node);
        
        if(parent!=null){
            node.left = parent.right;
            node.right = parent;
        }
        return left_res!=null?left_res:node;
    }
    
    TreeNode convert(TreeNode root){
        return dfs(root,null);
    }
