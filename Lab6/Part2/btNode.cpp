

#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
    if (bst_root == 0) return;
    int dumpIndex = 0;
    dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
    if (bst_root == 0) return;
    dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
    dumpArray[dumpIndex++] = bst_root->data;
    dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
    if (root == 0) return;
    tree_clear(root->left);
    tree_clear(root->right);
    delete root;
    root = 0;
}

int bst_size(btNode* bst_root)
{
    if (bst_root == 0) return 0;
    return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& root, int newInt)
{
    if (root == 0)
    {
        btNode* new_node = new btNode;
        new_node -> data = newInt;
        new_node -> left = 0;
        new_node -> right = 0;
        root = new_node;
    }
    
    else
    {
        btNode* cursor = root;
        bool done = false;
        while (!done)
        {
            if (newInt == cursor ->data)
            {
                done = true;
            }
            else if (newInt < cursor -> data)
            {
                if (cursor -> left == 0)
                {
                    btNode* new_node = new btNode;
                    new_node -> data = newInt;
                    new_node -> left = 0;
                    new_node -> right = 0;
                    
                    cursor -> left = new_node;
                    done = true;
                }
                else
                {
                    cursor = cursor -> right;
                }
            }
            else
            {
                if (cursor -> right == 0)
                {
                    btNode* new_node = new btNode;
                    new_node -> data = newInt;
                    new_node -> left = 0;
                    new_node -> right = 0;
                    
                    cursor -> right = new_node;
                    done = true;
                }
                else
                {
                    cursor = cursor -> right;
                }
            }
        }
    }
}

bool bst_remove(btNode*& root, int remInt)
{
    if (root == 0)
    {
        return false;
    }
    
    if (remInt < root -> data)
    {
        return bst_remove(root -> left, remInt);
    }
    
    if(remInt > root -> data)
    {
        return bst_remove(root -> right, remInt);
    }
    
    if (remInt == root -> data)
    {
        if(root -> left == 0)
        {
            btNode* oldroot_ptr = root;
            root = root -> right;
            delete oldroot_ptr;
            return true;
        }
        
        bst_remove_max(root -> left, root ->data);
        return true;
    }
    return false;
}

void bst_remove_max(btNode*& root, int& rootData)
{
    if (root -> right != 0)
    {
        return bst_remove_max(root -> right, rootData);
    }
    rootData = root -> data;
    if (root -> left == 0)
    {
        root = 0;
        return;
    }
    root = root -> left;
    return;
}


