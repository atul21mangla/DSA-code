#include<iostream>
using namespace std;

int countVowel(string str , int index){
    //! base case
    if(index==-1)return 0;
    if(str[index]=='a' || str[index]=='e' || str[index]=='i' || str[index]=='o' || str[index]=='u')
    return 1+countVowel(str,index-1);
    else
    return countVowel(str,index-1);

}

int main(){
    string str = "atul";
    cout<<countVowel(str,str.length()-1) << " vowels are there in (" << str << ")";
    return 0;
}