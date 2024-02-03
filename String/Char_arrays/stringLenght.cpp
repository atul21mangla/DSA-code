#include<iostream>
#include<cstring>
using namespace std;
int main(){
    // char str[10];         we cannot assign char arrays like this it will give error
    // str = "atul";
    char str[] = "coder atul";
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        count++,i++;
    }
    cout<<count<<endl;

    //* strlen function in cstring header file
    cout<<strlen(str)<<endl;
}