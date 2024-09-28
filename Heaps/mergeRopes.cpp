#include<bits/stdc++.h>
using namespace std;

int mergeRopes(vector<int>& arr){        //! TC - O(n log n)     
    int n = arr.size();                  //? SC - O(N) due to heaps 
    priority_queue<int , vector<int> , greater<int>>mh(arr.begin(),arr.end());

    int total_sum = 0;
    while(mh.size()>1){
        int x = mh.top();  // const
        mh.pop();          // O(log n)
        int y = mh.top();
        mh.pop();          // O(log n)

        total_sum += x + y;         
        mh.push(x+y);   // O(log n)
    }
    return total_sum;
}

int main(){
    vector<int>arr = {4,3,2,6};
    cout<<mergeRopes(arr)<<endl; 
    return 0;
}