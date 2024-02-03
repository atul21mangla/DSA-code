#include<iostream>
#include<cstring>
void myConcatenate(char* str1 , char* str2){
    int i = strlen(str1);
    int j = 0;
    while(str2[j] !='\0'){
        str1[i] = str2[j];
        i++,j++;
    }
}

using namespace std;

int main(){
    char str1[] = "Coder";
    char str2[] = "Atul";
    cout<<"before concatenation :"<<str1<<endl;
    // myConcatenate(str1,str2);
    strcat(str1,str2);
    cout<<"after concatenation :"<<str1<<endl;
}