#include<iostream>
using namespace std;

class Node
{
    friend class Tree;
    private:
    Node* left = NULL;
    Node* right = NULL;
    int data;

    public:
    Node(int v)
    {
        data = v;
    }

    Node* find(Node* ptr, int v)
    {
        if(ptr != NULL)
        {
        if(ptr->data != v)
        {
            if(v > ptr->data) return find(ptr->left, v);
            else return find(ptr->right, v);
        }
        else return ptr;
        }
        else return NULL;
        
    }
    
    void insert(Node* ptr, int v)
    {
        if(v > ptr->data)
        {
            if(ptr->left != NULL) insert(ptr->left, v);
            else
            {
                Node* tmp = new Node(v);
                ptr->left = tmp;
            }
        }
        else
        {
            if(ptr->right != NULL) insert(ptr->right, v);
            else
            {
                Node* tmp = new Node(v);
                ptr->right = tmp;
            }
        }
    }
    
    void print(Node* ptr, int space)
    {
        if(ptr != NULL)
        {
            space += 3;
            print(ptr->right,space);
            for(int i = 0; i < space; i++) cout << '.';
            cout << ptr->data << endl;
            print(ptr->left,space);
        }
        else return;
    }
};

class Tree
{
    friend class Node;
    private:
    Node* head = NULL;
    
    public:
    Tree(int v)
    {
        head = new Node(v);
    }

    void insert(int v)
    {
        head->insert(head,v);
    }
    
    void insert(int arr[], int size)
    {
        for(int i = 0; i < size; i++)
        {
            insert(arr[i]);
        }
    }
    
    Node* find(int v)
    {
        return head->find(head,v);
    }
    
    void print(int space)
    {
        head->print(head, space);
    }

};

int main()
{
    
    Tree t = Tree(10);
    t.insert(5);
    t.insert(6);
    t.insert(11);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.insert(12);
    t.insert(13);
    t.insert(14);
    t.insert(4);
    t.insert(2);
    t.insert(3);
    t.insert(1);
    cout << "Search for 6 " << t.find(6) << endl;
    cout << "Search for 12 " << t.find(12) << endl;
    cout << "Search for 5 " << t.find(5) << endl;
    cout << "Search for 11 " << t.find(11) << endl;
    cout << endl;
    t.print(1);
    
    cout<< "\n\n\n";
    
    Tree tt = Tree(10);
    int a[] = {5,6,11,7,8,9,12,13,14,4,2,3,1};
    tt.insert(a, sizeof(a)/sizeof(int));
    tt.print(1);
    return 0;
}