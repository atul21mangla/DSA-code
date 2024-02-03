//? PRINT STRINGS IN LEXOGRAPHICALLY ORDER
//* AND THEIR FREQUENCY ALSO

#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m[s]++;
    }

    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
}