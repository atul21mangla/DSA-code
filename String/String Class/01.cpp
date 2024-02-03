#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;       //? string class object declaration

    string str1 = "coding";  //! initialisation
    cout<<str1<<endl;                  //* here also '\0' is automatically added to last
    cout<<"length or size of str1 = "<<str1.size()<<endl;

    string str2;
    str2 = "atul mangla";     // correct in string class but give error in char arrays
    cout<<str2<<endl;

    cout<<"length or size of str2 = "<<str2.length()<<endl;

    //! reading input to string 
    string s;
    // cin>>s;        // stops as soon as encounters white space character
    getline(cin,s);
    cout<<s<<endl;


    // creating a copy of string

	string str3 = str2;  //string str3(str2); // copy constructor

	string str4;

	str4 = str2; // copy assignment operator

	cout << str3 << " " << str4 << endl;

    
    return 0;
}