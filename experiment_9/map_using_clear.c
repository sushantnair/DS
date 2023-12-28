#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, string> map1, map2; //Take any two maps
    //inserting values
    map1[1] = "India";
    map1[2] = "Nepal";
    map1[3] = "Sri Lanka";
    map1[4] = "Myanmar";
    cout<<"Map size before running function:\n"; //Print the size of map
    cout<<"map1 size = "<<map1.size()<<endl;
    cout<<"map2 size = "<<map2.size()<<endl;
    //Deleting the map elements
    map1.clear();
    map2.clear();
    cout<<"Map size after running function:\n"; //Print the size of map
    cout<<"map1 size = "<<map1.size()<<endl;
    cout<<"map2 size = "<<map2.size();
    return 0;
}
