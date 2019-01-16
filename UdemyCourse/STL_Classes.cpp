//--------------VECTOR--------------------------------//
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v={2,4,6,8,10};
    v.push_back(20);
    v.push_back(30);
    v.pop_back();
    
    vector<int>::iterator i;
    
    cout<<"Using iterator"<<endl;
    for(i=v.begin();i != v.end(); i++)
        cout<<++*i<<endl;
        //cout<<*i<<endl;
        
    cout<<"Using for_each_loop"<<endl;
    for(auto x:v)
        cout<<x<<endl;
    }
    
    
    
//--------------LINKED LIST (Doubly)--------------------------------//
#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> v={2,4,6,8,10};
    v.push_back(20);
    v.push_back(30);
    v.pop_back();
    
    list<int>::iterator i;
    
    cout<<"Using iterator"<<endl;
    for(i=v.begin();i != v.end(); i++)
        cout<<++*i<<endl;

    cout<<"Using for_each_loop"<<endl;
    for(auto x:v)
        cout<<x<<endl;
    }
        
 //--------------FORWARD LIST (Singly)--------------------------------//       
#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> v={2,4,6,8,10};
    v.push_front(20);
    v.push_front(30);
    v.pop_front(); //no push_back or push_front in forward list
    
    forward_list<int>::iterator i;
    
    cout<<"Using iterator"<<endl;
    for(i=v.begin();i != v.end(); i++)
        cout<<++*i<<endl;

    cout<<"Using for_each_loop"<<endl;
    for(auto x:v)
        cout<<x<<endl;
    }

//--------------------------- SET --------------------------------//   
#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> v={2,4,6,8,10,10};
    v.insert(20);
    v.insert(30);
    v.erase(20); //no push_back or push_front in forward list
    
    set<int>::iterator itr;
    
    cout<<"Using iterator"<<endl;
    for(itr=v.begin(); itr != v.end(); itr++)
        cout<<*itr<<endl;         //can't use ++*itr for container SET

    cout<<"Using for_each_loop"<<endl;
    for(auto x:v)
        cout<<x<<endl;
    }


//--------------------------MAP(hash table)-------------------//        
#include<iostream>
#include<map>
using namespace std;
//~~~~~map is useful when we have to do frequent search on data

int main()
{
    map<int,string> m;
    m.insert(pair<int,string>(1,"Jhon"));
    m.insert(pair<int,string>(2,"Ravi"));
    m.insert(pair<int,string>(3,"Khan"));
    m.insert(pair<int,string>(4,"Kiran"));
    
    map<int,string>::iterator itr;
    
    for(itr=m.begin();itr!=m.end();itr++)
    { 
      cout<<itr->first<<"  "<<itr->second<<endl;   
    }
    
    cout<<endl;
    //To search for a key
    map<int,string>::iterator itr1;
    itr1 = m.find(4);
    cout<<"Value found is:"<<endl;
    cout<<itr1->first<<"  "<<itr1->second<<endl;  
  
 }
        
        

        
        
