#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, float> rainfall_data;
    int i, n, value, flag = 0;
    string key, find_key;
    cout<<"Enter the number of records: ";
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        fflush(stdin);
        cout<<"\nEnter Key for record "<<i<<": ";
        cin>>key;
        if(i!=1)
            cin>>key;
        fflush(stdin);
        cout<<"\nEnter Value for record "<<i<<": ";
        cin>>value;
        rainfall_data.insert({key, value});
    }
    fflush(stdin);
    cout<<"KEYS\tVALUES\n";
    for(auto itr = rainfall_data.begin(); itr != rainfall_data.end(); itr++)
    {
        cout<<itr->first<<"\t"<<itr->second<<"\n";    
    }
    cout<<"Enter Key whose Value is to be found: ";
    cin>>find_key;
    cin>>find_key;
    for(auto itr = rainfall_data.begin(); itr != rainfall_data.end(); itr++)
    {
        if(find_key.compare(itr->first) == 0)
        {
            cout<<"Value "<<itr->second<<" is found.";
            flag++;
        }
        else
            continue;
    }
    if(flag == 0)
        cout<<"Value for the given key was not found.";
    return 0;
}
