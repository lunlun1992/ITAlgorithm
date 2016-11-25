#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;

class LinkedList
{
public:
    int val;
    LinkedList *next;
    LinkedList(int v): val(v){};
};
static const uint64_t __stl_prime_list[] =
{
        53,         97,           193,         389,       769,
        1543,       3079,         6151,        12289,     24593,
        49157,      98317,        196613,      393241,    786433,
        1572869,    3145739,      6291469,     12582917,  25165843,
        50331653,   100663319,    201326611,   402653189, 805306457,
        1610612741, 3221225473ul, 4294967291ul
};
class HashTable
{
public:
    HashTable(){size = 0;}
    void insert(int val);
    void del(int val);
    bool contain(int val);
    uint64_t size;
private:
    int hash_function(int key);
    uint64_t next_size();
    void refresh_table();
    vector<LinkedList *> inner_array;
};

int HashTable::hash_function(int key)
{
    return key % inner_array.size();
}

uint64_t HashTable::next_size()
{
    static int i = 0;
    return __stl_prime_list[i++];
}

void HashTable::refresh_table()
{
    if(size == inner_array.size())
    {
        uint64_t new_size = next_size();
        vector<LinkedList *> newnode(new_size, NULL);
        for(auto n : inner_array)
        {
            while(n)
            {
                LinkedList *temp = n;
                n = n->next;

                uint64_t newidx = temp->val % size;
                if(newnode[newidx] == NULL)
                {
                    newnode[newidx] = temp;
                }
                else
                {
                    temp->next = newnode[newidx]->next;
                    newnode[newidx]->next = temp;
                }
            }
        }
        inner_array.swap(newnode);
    }
}
void HashTable::insert(int val)
{
    refresh_table();
    if(contain(val))
        return;
    size++;
    int key = hash_function(val);
    LinkedList *t = inner_array[key];
    if(!t)
    {
        inner_array[key] = new LinkedList(val);
    }
    else
    {
        LinkedList *l = new LinkedList(val);
        l->next = inner_array[key]->next;
        inner_array[key]->next = l;
    }
}

void HashTable::del(int val)
{
    if(!contain(val))
        return;
    int key = hash_function(val);
    LinkedList *l = inner_array[key];
    if(l->val == val)
    {
        delete inner_array[key];
        inner_array[key] = NULL;
        return;
    }
    while(l && l->next->val != val)
        l = l->next;
    LinkedList *temp = l->next;
    l->next = l->next->next;
    delete temp;
}

bool HashTable::contain(int val)
{
    if(size == 0)
        return false;
    int key = hash_function(val);
    LinkedList *t = inner_array[key];
    if(!t)
    while(t && t->val != val)
        t = t->next;
    if(t)
        return true;
    else
        return false;
}

int main()
{
    HashTable hashTable;
    cout << hashTable.contain(12) << endl;
    hashTable.insert(1);
    cout << hashTable.contain(1) << endl;
    hashTable.del(1);
    cout << hashTable.contain(1) << endl;
    hashTable.insert(1);
    hashTable.insert(54);
    hashTable.insert(107);
    cout << hashTable.contain(1) << endl;
    cout << hashTable.contain(54) << endl;
    cout << hashTable.contain(107) << endl;
    return 0;
}