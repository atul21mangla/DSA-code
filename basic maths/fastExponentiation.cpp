#include<iostream>
using namespace std;

int fastExponentiation(int a , int b){      // TC = O(log b)
    int ans = 1;
    while(b>0){
        if(b & 1){    //  if b is odd 
            ans = ans*a;
        }
        a = a*a;
        b = b>>1;
    }
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    int ans = fastExponentiation(a,b);
    cout<<a<<" to the power "<<b<<" is : "<<ans;
    return 0;
}