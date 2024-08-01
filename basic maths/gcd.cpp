#include<iostream>
using namespace std;

int gcd(int a , int b){
    if(b == 0)return a;
    if(a == 0)return b;
    while(a>0 && b>0){
        if(a >= b){
            a -= b;
        }
        else if(b > a){
            b -= a;
        }
    }
    // matlab koi ek zero ho chuka hai
    // check krna hai kon zero hua hai
    return (a == 0)? b : a;
}

int main(){
    int a,b;
    cin>>a>>b;
    int ans = gcd(a,b);
    cout<<"The gcd of "<<a<<" and "<<b<<" is : "<<ans<<endl;
    return 0;
}