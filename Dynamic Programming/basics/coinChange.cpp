#include<bits/stdc++.h>
using namespace std;

int recursiveFun(vector<int>& coins , int amount){
    for(int i=0;i<coins.size(),i++){
        int x = recursiveFun(coins , amount-coins[i]);
    }
}

int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;

    cout << recursiveFun(coins,amount) << endl; 
    return 0;
}