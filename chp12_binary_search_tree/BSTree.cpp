#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int val;
    TreeNode(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
    }
};

class BSTree
{
public:
    bool isempty(){ return size == 0;}
    TreeNode *search(int val);
    TreeNode *minimum(TreeNode *node);
    TreeNode *maximum(TreeNode *node);
    TreeNode *pre(TreeNode *node);
    TreeNode *suc(TreeNode *node);
    void insertnode(int val);
    void deletenode(TreeNode *node);
    void transplant(TreeNode *src, TreeNode *dst);
    TreeNode *root;
    BSTree();
    void printTree(TreeNode *node, int blk);
private:
    size_t size;

};

BSTree::BSTree()
{
    size = 0;
    root = NULL;
}

TreeNode* BSTree::search(int val)
{
    TreeNode *node = root;
    while(node)
    {
        if(node->val > val)
            node = node->left;
        else if(node->val < val)
            node = node->right;
        else
            break;
    }
    return node;
}

TreeNode* BSTree::minimum(TreeNode *node)
{
    while(node && node->left)
        node = node->left;
    return node;
}

TreeNode* BSTree::maximum(TreeNode *node)
{
    while(node && node->right)
        node = node->right;
    return node;
}

TreeNode* BSTree::pre(TreeNode *node)
{
    if(node->left)
        return maximum(node->left);
    TreeNode *p = node->parent;
    while(p && p->left == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
}

TreeNode* BSTree::suc(TreeNode *node)
{
    if(node->right)
        return minimum(node->right);
    TreeNode *p = node->parent;
    while(p && p->right == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
}

void BSTree::insertnode(int val)
{
    TreeNode *node = root;
    TreeNode *p = NULL;
    while(node)
    {
        p = node;
        if(node->val > val)
            node = node->left;
        else if(node->val < val)
            node = node->right;
        else
            break;
    }
    if(node)
        return;
    node = new TreeNode(val);
    if(p == NULL)
        root = node;
    node->parent = p;
    if(val < p->val)
        p->left = node;
    else
        p->right = node;
}

void BSTree::transplant(TreeNode *src, TreeNode *dst)
{
    if(dst->parent == NULL)
        root = src;
    else if(dst->parent->left == dst)
        dst->parent->left = src;
    else
        dst->parent->right = src;
    if(src)
        src->parent = dst->parent;
}

void BSTree::deletenode(TreeNode *node)
{
    if(!node)
        return;
    if(!node->left)
        transplant(node->right, node);
    else if(!node->right)
        transplant(node->left, node);
    else
    {
        TreeNode *swi = minimum(node->right);
        if(swi->parent != node)
        {
            transplant(swi->right, swi);
            swi->right = node->right;
            node->right->parent = swi;
        }
        transplant(swi, node);
        swi->left = node->left;
        node->left->parent = swi;
    }
}

void BSTree::printTree(TreeNode *node, int blk)
{
    for(int i = 0; i < blk; i++)
        printf("\t");
    printf("|—<%d>\n", node->val);
    if(node->left)
        printTree(node->left, blk + 1);
    if(node->right)
        printTree(node->right, blk + 1);
}

int main()
{
    BSTree bsTree;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);
    t4->left = t2;
    t4->right = t6;
    t2->parent = t4;
    t6->parent = t4;
    t2->left = t1;
    t2->right = t3;
    t1->parent = t2;
    t3->parent = t2;
    t6->left = t5;
    t6->right = t7;
    t5->parent = t6;
    t7->parent = t6;
    bsTree.root = t4;
//    for(int i = 0; i <= 8; i++)
//        cout << bsTree.search(i) << endl;
    bsTree.insertnode(15);
    bsTree.printTree(bsTree.root, 1);
    bsTree.insertnode(10);
    bsTree.printTree(bsTree.root, 1);
    bsTree.insertnode(20);
    bsTree.printTree(bsTree.root, 1);
    bsTree.insertnode(18);
    bsTree.printTree(bsTree.root, 1);
    bsTree.insertnode(21);
    bsTree.printTree(bsTree.root, 1);
    bsTree.deletenode(bsTree.search(15));
    bsTree.printTree(bsTree.root, 1);
    return 0;
}