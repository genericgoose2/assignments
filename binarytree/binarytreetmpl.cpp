#include<iostream>
using namespace std;

template <typename T> class Node
{
    public:
    Node* left = NULL;
    Node* right = NULL;
    T data;

    Node(T v)
    {
        data = v;
    }

    Node* find(Node* ptr, T v)
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
    
    void insert(Node* ptr, T v)
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

template <typename T> class Tree
{
    public:
    Node<T>* head = NULL;
    
    Tree(T v)
    {
        head = new Node<T>(v);
    }

    void insert(T v)
    {
        head->insert(head,v);
    }
    
    void insert(T arr[], int size)
    {
        for(int i = 0; i < size; i++)
        {
            insert(arr[i]);
        }
    }
    
    Node<T>* find(T v)
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

    Tree<int> t = Tree<int>(10);
    int a[] = {5,6,11,7,8,9,12,13,14,4,2,3,1};
    t.insert(a, sizeof(a)/sizeof(int));
    t.print(2);
    
    cout << "\n\n\n";
    
    Tree<float> tt = Tree<float>(10);
    float b[] = {4.3,0.2,1.1,3.5, 13.4,12.3,7.8, 7.5,7.9,14.2};
    tt.insert(b, sizeof(b)/sizeof(float));
    tt.print(2);
    
    return 0;
}