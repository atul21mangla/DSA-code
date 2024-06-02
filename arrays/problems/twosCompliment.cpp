#include<bits/stdc++.h>
using namespace std;

void printarr(vector<int> arr){
    for(vector<int>:: iterator it=arr.begin();it!=arr.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl<<"-------------------------------------------"<<endl;
}

void find2sCompliment(vector<int> bin){
    int n = bin.size();
    vector<int>twosComp(n+1,0);
    cout<<"Initially twos compliment array ."<<endl;
    printarr(twosComp);
    //! step 1 
    //? find 1's compliment by flipping each bit in bin array 
    for(int i=n-1;i>=0;i--){
        twosComp[i+1] = (bin[i] == 0) ? 1 : 0;
    }

    cout<<"after flipping bits twos compliment array."<<endl;
    printarr(twosComp);

    //! step 2
    //* add 1
    int carry = 1;
    for(int i=n-1;i>=0;i--){
        int sum = twosComp[i+1] + carry;
        twosComp[i+1] = sum%2;
        carry = sum/2;
    }
    if(carry){
        twosComp[0] = (carry);
    }
    cout<<"Finally twos compliment array."<<endl;
    printarr(twosComp);
}

int main(){
    vector<int>bin = {0,1,0,1,0,0};
    find2sCompliment(bin);
    return 0;
}