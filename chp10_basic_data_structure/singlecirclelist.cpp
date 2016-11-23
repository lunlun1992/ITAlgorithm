#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;
    ListNode(int val)
    {
        this->val = val;
    }
    ListNode(){};
};

class SingleCircleList
{
private:
    ListNode *H;
public:
    SingleCircleList();
    void insertnode(ListNode *node);
    void deletenode(int val);
    ListNode *searchnode(int val);
};

SingleCircleList::SingleCircleList()
{
    H = new ListNode();
    H->next = H;
}

void SingleCircleList::insertnode(ListNode *node)
{
    node->next = H->next;
    H->next = node;
}

void SingleCircleList::deletenode(int val)
{
    H->val = val;
    ListNode *temp = H;
    while(temp->next->val != val)
        temp = temp->next;
    if(temp->next != H)
    {
        ListNode *todel = temp->next;
        temp->next = temp->next->next;
        delete todel;
    }
}

ListNode* SingleCircleList::searchnode(int val)
{
    H->val = val;
    ListNode *temp = H->next;
    while(temp->val != val)
        temp = temp->next;
    if(temp != H)
        return temp;
    else
        return NULL;
}

int main()
{
    SingleCircleList sl;
    sl.deletenode(1232);
    sl.insertnode(new ListNode(1));
    sl.deletenode(2);
    cout << sl.searchnode(1) << endl;
    sl.deletenode(1);
    cout << sl.searchnode(1) << endl;
    return 0;
}