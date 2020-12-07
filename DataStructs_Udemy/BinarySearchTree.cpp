#include <iostream>
using namespace std;

class Node
{
    public:
     Node* lchild;
     int data;
     Node* rchild;
};

class BST
{
    private:
     Node* root;
    public:
     BST() {root = nullptr;}  // Constructor
     Node* getRoot() {return root;} // Accessor
     //Functions
     void Insert(int key);
     void Inorder(Node* p);
     Node* Search(int key);
};

void BST::Insert(int key)
{
    Node *t = root;
    Node* p;
    Node* r;
    //First Node
    if(root == nullptr)
    {
        p = new Node; p->data = key; p->lchild = p->rchild = nullptr;
        root = p; return;
    }
    //Find the insertion point
    while(t != nullptr)
    {
        r=t;
        if(key == t->data) return;
        else if(key < t->data) t=t->lchild;
        else t=t->rchild;
    }
    //Now t points at NULL and r points at insertion Node
    p=new Node; p->data = key; p->lchild = p->rchild = nullptr;
    if(key<r->data) r->lchild = p;
    else r->rchild = p;
}

void BST::Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<", "<<flush;
        Inorder(p->rchild);
    }
}

Node* BST::Search(int key)
{
    Node* t = root;
    while(t!=nullptr)
    {
        if(key == t->data) return t;
        else if(key<t->data) t= t->lchild;
        else t=t->rchild;
    }
    return nullptr;
}

int main()
{
    BST bst;
    
    bst.Insert(10); bst.Insert(5); bst.Insert(20);
    bst.Insert(8); bst.Insert(30);
    
    bst.Inorder(bst.getRoot());
    
    Node* temp = bst.Search(20);
    if(temp != nullptr) cout<<endl<<"Found "<<temp->data;
    else cout<<endl<<"Not found";

    return 0;
}
