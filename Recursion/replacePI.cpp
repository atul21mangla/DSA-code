#include<iostream>
using namespace std;

void replacePI(char* ch ,int i){
    // Base Case
    if(ch[i] == '\0')return;

    if(ch[i]=='p' && ch[i+1]=='i'){
        // ....
        // finding null character first
        int nullIndex = i+2;
        while(ch[nullIndex]!='\0')nullIndex++;
        while(nullIndex>i+1){
            ch[nullIndex+2] = ch[nullIndex];
            nullIndex--;
        }

        ch[i] = '3';
        ch[i+1] = '.';
        ch[i+2] = '1';
        ch[i+3] = '4';

        // Recursive Case to my friend
        replacePI(ch,i+4);
    }
    replacePI(ch,i+1);
}

int main(){
    // char ch[20] = "pip";   // replace pi with "3.14"
    char ch[20] = "pippi";
    replacePI(ch,0);
    cout<<ch;  
}