#include <iostream>
#include<stack>
#include<limits.h>
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
     
     Node* R_Insert(Node* p, int key);
     Node* R_Search(Node* p, int key);
     
     Node* Delete(Node* p, int key);
     int Height(Node* p);
     Node* InPredecessor(Node* p);
     Node* InSuccessor(Node* p);
     
     void CreateFromPreOrder(int *pre, int n);
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
        cout<<p->data<<" "<<flush;
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

Node* BST::R_Insert(Node* p, int key)
{
    if(p==nullptr) 
    {
       Node* t = new Node; t->data = key; t->lchild = t->rchild = nullptr;
       return t; 
    }
    if(key < p->data) p->lchild = R_Insert(p->lchild, key);
    else if (key > p->data) p->rchild = R_Insert(p->rchild, key);
    return p;
}

Node* BST::R_Search(Node* p, int key)
{
    if(p==nullptr) return nullptr;
    if(key==p->data) return p;
    else if(key < p->data) return R_Search(p->lchild, key);
    else return R_Search(p->rchild, key);
}

int BST::Height(Node* p)
{
    if(p==nullptr) return 0;
    int l = Height(p->lchild);
    int r = Height(p->rchild);
    return l>r? l+1:r+1;
}

Node* BST::InPredecessor(Node* p)
{
    while(p && p->rchild != nullptr) p=p->rchild;
    return p;
}

Node* BST::InSuccessor(Node* p)
{
    while(p && p->lchild != nullptr) p=p->lchild;
    return p;
}

Node* BST::Delete(Node* p, int key)
{
    Node* q;
    if(p==nullptr) return nullptr; 
    if(p->data == key && p->lchild ==nullptr && p->rchild == nullptr) //leaf node/single node BST
    {
        if(p==root) root = nullptr;
        delete p;
        return nullptr;
    }
    if(key < p->data)  p->lchild = Delete(p->lchild,key);
    else if (key>p->data)  p->rchild = Delete(p->rchild,key);
    else if(key == p->data)
    { 
        if(Height(p->lchild) > Height(p->rchild))
        {
            q=InPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q=InSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void BST::CreateFromPreOrder(int *pre, int n)
{
    int i=0;
    root = new Node;
    root->data = pre[i++]; root->lchild = root->rchild = nullptr;
    
    Node* t;
    Node* p = root;
    stack<Node*> stk;
    while(i<n)
    {
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++]; t->lchild = t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p=t;
        }
        else if(pre[i] > p->data && pre[i]<(stk.empty() ? INT_MAX : stk.top()->data))
        {
            t= new Node;
            t->data = pre[i++]; t->lchild = t->rchild = nullptr;
            p->rchild = t;
            p=t;
        }
        else 
        {
            p= stk.top();
            stk.pop();
        }
    }
}

int main()
{
    BST bst;
    
    bst.Insert(10); bst.Insert(5); bst.Insert(20);
    bst.Insert(8); bst.Insert(30);                      // Insert
    
    bst.Inorder(bst.getRoot()); cout<<endl;
    
    Node* temp = bst.Search(20);                        // Search
    if(temp != nullptr) cout<<"Found "<<temp->data<<endl;
    else cout<<"Not found"<<endl;
    
    bst.R_Insert(bst.getRoot(), 33);                    // Recursive Insert
    bst.Inorder(bst.getRoot()); cout<<endl;
    
    temp = bst.R_Search(bst.getRoot(), 33);             // Recursive Search
    if(temp != nullptr) cout<<"Found "<<temp->data<<endl;
    else cout<<"Not found"<<endl;
    
    cout<<"Height "<<bst.Height(bst.getRoot())<<endl;   // Height
    
    bst.Delete(bst.getRoot(),33);                       // Delete
    bst.Inorder(bst.getRoot());
    
    BST b;
    int pre[]={30,20,10,15,25,40,50,45};
    b.CreateFromPreOrder(pre,sizeof(pre)/sizeof(pre[0]));
    cout<<endl;
    b.Inorder(b.getRoot());

    return 0;
}
