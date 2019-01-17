#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Item
{
private:
    string name;
    float price;
    float qty;
public:
    Item(){};
    Item(string n, float p, float q);
    friend ofstream & operator<<(ofstream &ofs, Item &i);
    friend ifstream & operator>>(ifstream &ifs, Item &i);
    friend ostream & operator<<(ostream &os, Item &i);
};
//function definitions
Item::Item(string n, float p, float q)
{
    name = n; price = p; qty =q;
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
ostream & operator<<(ostream &os, Item &i)
{
    os<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
    return os;
}

//main function
int main()
{
    int n;
    cout<<"Enter the no. of items: "<<endl;
    cin>>n;
    
    //Get details from user
    string name; float price; float qty;
    vector<Item *>stuff;
    cout<<"Enter the items"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the item "<<i+1<<" details:"<<endl;
        cin>>name;
        cin>>price;
        cin>>qty;
        stuff.push_back(new Item(name, price, qty)); 
    }
    
    //Save details to a file
    ofstream ofs("Items.txt");
    vector<Item *>::iterator itr;
    for(itr=stuff.begin();itr!=stuff.end();itr++)
    {
        ofs<<**itr;
    }
    //Read details from the file
    Item item;
    ifstream ifs("Items.txt");
    for(int i=0;i<n;i++)
    {
        ifs>>item;
        cout<<"Item "<<i+1<<" details"<<endl<<item<<endl;
    }
    
}


