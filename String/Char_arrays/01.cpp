#include<iostream>
using namespace std;

void readString(char arr[],char dlim='\n'){         //? default parameter
    char ch;
    int i = 0;
    while(true){
        ch = cin.get();
        if(ch == dlim){
            break;
        }
        arr[i++] = ch;
    }
    arr[i] = '\0';
}
int main(){
    char str1[6]= {'a','v','b','r','u','\0'};
    cout<<str1<<endl;

    //* initialisation with string literal
    char str2[] = "coding"; //? '\0' is auto. added at the end of the string

	cout << str2 << endl;

	//! char str3[5] = "hello"; // error due to wrong size declaration



    //? reading input in char array.
    char arr[101];       //* according to constraints
    // cin>>arr;
    // cout<<arr;

    readString(arr,'$');     // or we can write withuot delimiting character bcoz of default parameter in function
    cout<<"you have entered "<<arr<<endl;

    //* another approach to be most used
    char str[101];
    cin.getline(str,5,'#');     // '\n' is default arguement     //? jo criteria pehle milega vo follow hoga from 2nd and 3rd arguement
    cout<<"you have entered "<<str;
}