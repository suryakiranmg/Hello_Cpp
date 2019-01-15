# include<iostream>
#include<fstream>
using namespace std;

class Item
{
private:
    string name;
    float price;
    int qty;
public:
    Item() {};
    Item(string n, float p, int q);
    friend ifstream & operator>>(ifstream &ifs, Item &i);
    friend ofstream & operator<<(ofstream &ofs, Item &i);
    friend ostream & operator<<(ostream &os,Item &i);
};

Item::Item(string n,float p,int q)
{
    name = n;price =p; qty = q;
}

ofstream & operator<<(ofstream &ofs, Item &i)
{
    ofs<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Item &i)
{
    ifs>>i.name>>i.price>>i.qty;
    return ifs;
}

ostream & operator<<(ostream &os,Item &i)
{
os<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
return os;
}

int main()
{
    //Prompt user 
    int n;
    cout<<"Enter the no. of Items: "<<endl;
    cin>>n; cout<<n<<endl;
    
    // Get the date from user
    Item *list[n];
    string name; float price; int qty;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter name, price, qty of item no. "<<i+1<<endl;
        cin>>name; cin>>price; cin>>qty;
        list[i] = new Item(name, price, qty);
    }
    
    //Save info to a file
    ofstream ofs("Items.txt");
    for(int i=0;i<n;i++)
    {
       ofs<<*list[i];
    }
    
    //Read from file
    ifstream ifs("Items.txt");
    Item i1;
    for(int i=0;i<n;i++)
    {
        ifs>>i1;
        cout<<"Item "<<i+1<<" details: "<<endl;
       cout<<i1<<endl;         //ostream needed for this
    }
}




