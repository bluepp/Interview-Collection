/*
  bluepp
  2014-12-30
  May the force be with me!
  
  Convert Binary Search Tree (BST) to Sorted Doubly-Linked List
*/


/* v2, my version */
//convert binary search tree to sorted doubly linked list

Node *TreeToList(Node *root)
{
    Node *head = NULL;
    
    _convert(root, NULL, head);
    return head;
}

void _convert(Node *p, Node *&prev, Node *&head)
{
    if (!p) return;
    
    _convert(p->left, prev, head);
    
    if (prev)
        p->left = prev;
    else
        head = p;
    
    Node *right = p->right;
    if (head) 
    {
        head->left = p;
        p->right = head;
    }
    
    prev = p;
    
    _convert(right, prev, head);
}


/* http://leetcode.com/2010/11/convert-binary-search-tree-bst-to.html */
//convert binary search tree to sorted doubly linked list

Node *TreeToList(Node *root)
{
    Node *prev = NULL;
    Node *head = NULL;
    
    _convert(root, prev, head);
    
    return head;
}

void _convert(Node *p, Node *&prev, Node *&head)
{
    if (!p) return;
    
    _convert(p->left, prev, head);
    
    p->left = prev;
    if (prev)
        prev->right = p;
    else 
        head = p;
    
    Node *right = p->right;
    head->left = p;
    p->right = head;
    
    prev = p
    _convert(right, prev, head);
}

  
