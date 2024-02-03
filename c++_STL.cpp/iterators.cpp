#include<bits/stdc++.h>
using namespace std;
int main(){
    // vector<int>v = {1,2,3,4};

    //! vector<int>::iterator it;
    // for(auto it=v.begin();it!=v.end();it++){
    //     cout<<(*it)<<" ";
    // }

    //? PAIRS
    // vector<pair<int,int>>v = {{1,2},{2,3},{3,4}};
    // vector<pair<int,int>> :: iterator it;
    // for(it=v.begin();it<v.end();it++){
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    //     //* it->first <=> (*it).first  
    // }

    //! ENHANCED FOR LOOPS 

    vector<int>v = {1,2,4,5};
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<pair<int,string>>v1;
    v1.emplace_back(2,"Atul");
    v1.emplace_back(make_pair(2,"rahul"));
    v1.push_back({3,"x"});
    for(pair<int,string> y : v1){
        cout<<y.first<<" "<<y.second<<endl;
    }

}