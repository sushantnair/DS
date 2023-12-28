#include<bits/stdc++.h>
using namespace std;
int main()
{
    //initialize container
    map<int, int> mp;
    //insert elements in random order
    mp.insert({2, 30});
    mp.insert({1, 40});
    mp.insert({3, 60});
    mp.insert({5, 50});
    //print the elements
    cout<<"The map before using erase() is -\n";
    cout<<"Key\tElement\n";
    for(auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout<<itr->first<<"\t"<<itr->second<<"\n";
    }
    //function to erase keys
    mp.erase(1);
    mp.erase(2);
    cout<<"The map after applying erase() is -\n";
    cout<<"Key\tElement\n";
    for(auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout<<itr->first<<"\t"<<itr->second<<"\n";
    }
    return 0;
}
