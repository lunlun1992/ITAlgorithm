#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

void preorder(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode *t = st.top();
        st.pop();
        if(!t)
            continue;
        cout << t->val << endl;
        st.push(t->right);
        st.push(t->left);
    }
}

void inorder(TreeNode *root)
{
    stack<TreeNode *> st;

    while(1)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        if (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            cout << temp->val << endl;
            root = temp->right;
        }
        else
            break;
    }
}

void postorder(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *lastone = NULL;
    while(!st.empty() || root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        if (!st.empty())
        {
            if(root->right == NULL || root->right == lastone)
            {
                cout << root->val << endl;
                st.pop();
                lastone = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }

        }
    }
}

int main()
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    postorder(t1);
    return 0;
}
