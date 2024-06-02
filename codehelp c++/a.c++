#include<bits/stdc++.h>
using namespace std;

int decimalToBinary(int n) {
    int b_no = 0;
    int i = 0;
    while (n > 0) {
        int bit = (n&1);
        b_no = bit*pow(10, i) + b_no ;
        n = n>>1;
        i++;
    }
    return b_no;
}

int binaryToDecimal(int n) {
    int d_no = 0;
    int i = 0;
    while (n > 0) {
        int bit = n%10;
        d_no = bit*pow(2, i++) + d_no ;
        n /= 10 ;
    }
    return d_no;
}

int main(){
    int n,binary_no;
    cout<<"Enter number to convert to Binary."<<endl;
    cin>>n;
    binary_no= decimalToBinary(n);
    cout<<binary_no<<" is the converted binary equivalent of "<<n<<endl;
    cout<<binaryToDecimal(1010101);
    return 0;
}

