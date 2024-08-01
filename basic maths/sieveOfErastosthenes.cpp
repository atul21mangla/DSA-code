#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){
    vector<bool>isPrime(n+1 , true);
    isPrime[0] = isPrime[1] = false;

    for(int i =2 ; i*i<=n ; i++){          // TC = O(N loglog N)
        if(isPrime[i]){
            for(int j = i*i ; j<=n ; j+=i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main(){
    int n;
    cin>>n;
    vector<bool>prime = sieve(n);
    for(int i=0;i<=n;i++){                        //* prints the primes from 0 to N
        if(prime[i])cout<<i<<" ";
    }
    return 0;
}