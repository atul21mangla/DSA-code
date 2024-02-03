
//* ARRAY OF VECTORS

#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int N;
    cin>>N;
    vector<int>v[N];
    for(int i=0;i<N;i++){
        int n;  // size of each vector in array
        cin>>n;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }

    for(int i=0;i<N;i++){
        printvector(v[i]);
        cout<<endl;
    }
    
}