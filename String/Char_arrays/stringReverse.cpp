#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void myreverse(char* str){
    int i = 0;
    int j = strlen(str)-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
}

int main(){
    char str[] = "coding";
    int n = strlen(str);
    cout<<"original string :"<<str<<endl;

    myreverse(str);
    cout<<"After reversing :"<<str<<endl;

    //? reverse function
    reverse(str,str+n);
    cout<<"After again reversing :"<<str<<endl;
}