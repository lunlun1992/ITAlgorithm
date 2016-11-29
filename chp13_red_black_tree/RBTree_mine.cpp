#include <iostream>
using namespace std;

enum TREENODECOLOR
{
    RED,
    BLACK
};

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int val;
    TREENODECOLOR color;
    TreeNode(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
        this->color = RED;
    }
    TreeNode(TREENODECOLOR color)
    {
        this->val = 0;
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
        this->color = color;
    }
};

class RBTree
{
public:
    bool isempty(){ return size == 0;}
    TreeNode *search(int val);
    TreeNode *minimum(TreeNode *node);
    TreeNode *maximum(TreeNode *node);
    TreeNode *pre(TreeNode *node);
    TreeNode *suc(TreeNode *node);
    void leftrotate(TreeNode *node);
    void rightrotate(TreeNode *node);
    void insertnode(int val);
    void deletenode(TreeNode *node);
    void transplant(TreeNode *src, TreeNode *dst);
    void insert_fixtree(TreeNode *node);
    void delete_fixtree(TreeNode *node);
    TreeNode *root;
    RBTree();
    void printTree(TreeNode *node, int blk);
    static TreeNode *pnull;
private:
    size_t size;
};

RBTree::RBTree()
{
    size = 0;
    root = pnull;
    pnull = new TreeNode(BLACK);
}

TreeNode* RBTree::search(int val)
{
    TreeNode *node = root;
    while(node != pnull)
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

TreeNode* RBTree::minimum(TreeNode *node)
{
    while(node != pnull && node->left)
        node = node->left;
    return node;
}

TreeNode* RBTree::maximum(TreeNode *node)
{
    while(node != pnull && node->right)
        node = node->right;
    return node;
}

TreeNode* RBTree::pre(TreeNode *node)
{
    if(node->left != pnull)
        return maximum(node->left);
    TreeNode *p = node->parent;
    while(p != pnull && p->left == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
}

TreeNode* RBTree::suc(TreeNode *node)
{
    if(node->right != pnull)
        return minimum(node->right);
    TreeNode *p = node->parent;
    while(p != pnull && p->right == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
}

void RBTree::leftrotate(TreeNode *node)
{
    TreeNode *r = node->right;

    if(r->left != pnull)
        r->left->parent = node;
    node->right = r->left;

    if(node->parent == pnull)
        root = r;
    else if(node == node->parent->left)
        node->parent->left = r;
    else
        node->parent->right = r;
    r->parent = node->parent;

    r->left = node;
    node->parent = r;
}

void RBTree::rightrotate(TreeNode *node)
{
    TreeNode *r = node->left;

    if(r->right != pnull)
        r->right->parent = node;
    node->left = r->right;

    if(node->parent == pnull)
        root = r;
    else if(node == node->parent->left)
        node->parent->left = r;
    else
        node->parent->right = r;
    r->parent = node->parent;

    r->right = node;
    node->parent = r;
}

void RBTree::insertnode(int val)
{
    TreeNode *node = root;
    TreeNode *p = pnull;
    while(node != pnull)
    {
        p = node;
        if(node->val > val)
            node = node->left;
        else if(node->val < val)
            node = node->right;
        else
            break;
    }
    if(node != pnull)
        return;

    node = new TreeNode(val);
    node->parent = p;
    if(p == pnull)
        root = node;
    if(val < p->val)
        p->left = node;
    else
        p->right = node;
    node->left = pnull;
    node->right = pnull;
    node->color = RED;
    insert_fixtree(node);
}

void RBTree::insert_fixtree(TreeNode *node)
{
    while(node->parent->color == RED)
    {
        if(node->parent == node->parent->parent->left)
        {
            TreeNode *p = node->parent->parent->right;
            if(p->color == RED)
            {
                node->parent->color = BLACK;
                p->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else if(node == node->parent->right)
            {
                node = node->parent;
                leftrotate(node);
            }
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            rightrotate(node->parent->parent);
        }
        else
        {
            TreeNode *p = node->parent->parent->left;
            if(p->color == RED)
            {
                node->parent->color = BLACK;
                p->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else if(node == node->parent->left)
            {
                node = node->parent;
                rightrotate(node);
            }
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            leftrotate(node->parent->parent);
        }
    }
    root->color = BLACK;
}

void RBTree::transplant(TreeNode *src, TreeNode *dst)
{
    if(dst->parent == pnull)
        root = src;
    else if(dst->parent->left == dst)
        dst->parent->left = src;
    else
        dst->parent->right = src;
    src->parent = dst->parent;
}

void RBTree::deletenode(TreeNode *node)
{
    if(node == pnull)
        return;
    TreeNode *p = node;
    TreeNode *tofix = pnull;
    TREENODECOLOR oricolor = p->color;
    if(node->left == pnull)
    {
        tofix = node->right;
        transplant(node->right, node);
    }
    else if(node->right == pnull)
    {
        tofix = node->left;
        transplant(node->left, node);
    }
    else
    {
        p = minimum(node->right);
        oricolor = p->color;
        tofix = p->right;
        if (p->parent == node)
            tofix->parent = p;
        else {
            transplant(p->right, p);
            p->right = node->right;
            node->right->parent = p;
        }
        transplant(p, node);
        p->left = node->left;
        node->left->parent = p;
        p->color = node->color;
    }
    if(oricolor == BLACK)
        delete_fixtree(tofix);
}

void RBTree::delete_fixtree(TreeNode *node)
{
    while(node != pnull && node->color == BLACK)
    {
        if(node == node->parent->left)
        {
            TreeNode *w = node->parent->right;
            if(w->color == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                leftrotate(node->parent);
            }
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                node = node->parent;
            }
            else if(w->right->color == BLACK)
            {
                w->left->color = BLACK;
                w->color = RED;
                rightrotate(w);
                w = node->parent->right;
            }
            w->color = node->parent->color;
            node->parent->color = BLACK;
            w->right->color = BLACK;
            leftrotate(node->parent);
            node = root;
        }
        else
        {
            TreeNode *w = node->parent->left;
            if(w->color == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                leftrotate(node->parent);
            }
            if(w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                node = node->parent;
            }
            else if(w->left->color == BLACK)
            {
                w->right->color = BLACK;
                w->color = RED;
                leftrotate(w);
                w = node->parent->left;
            }
            w->color = node->parent->color;
            node->parent->color = BLACK;
            w->left->color = BLACK;
            rightrotate(node->parent);
            node = root;
        }
    }
    node->color = BLACK;
}

void RBTree::printTree(TreeNode *node, int blk)
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
    RBTree bsTree;
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