#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool isAnagram(char* str1 , char* str2){
    int freq[26] = {0};
    
    int i = 0;
    while(str1[i] !='\0'){
        char ch = str1[i];
        int idx = ch - 'a';
        freq[idx]++;
        i++;
    }

    int j = 0;
    while(str2[j] !='\0'){
        freq[str2[j] - 'a']--;
        j++;
    }

    //? checking if frq array is completly 0 or not
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    char str1[] = "taste";
    char str2[] = "state";
    if(isAnagram(str1,str2)){
        cout<<"yes given strings are anagrams."<<endl;
    }
    else{
        cout<<"No given strings are not anagrams."<<endl;
    }
    return 0;
}