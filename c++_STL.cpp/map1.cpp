#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string>m;
    m.insert(make_pair(1,"atul"));
    m[2] = "ssdcdc";
    m[7] = "bdgd";                        //! all operations take o(log n) time
    m.insert({3,"asad"});
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    map<int,string>::iterator it = m.find(3);   //* auto it = m.find(3);
    if(it == m.end())
    cout<<"key not present";
    else
    cout<<(*it).second;

    //? m.erase()      you can give key or iterator pointing to some key inside this erase method
}