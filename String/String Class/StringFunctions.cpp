#include<bits/stdc++.h>
using namespace std;
int main(){

    //! finding length of string class object
    string str1 = "hello atul";
    cout<<"length of ("<<str1<<") = "<<str1.length()<<endl;
    cout<<"size of ("<<str1<<") = "<<str1.size()<<endl;

    //! appending / concatenating str2 to str1

    string str2 = " mr. coder";

    //? 1. using append()

    // str1.append(str2);
    // cout<< str1 << " , " << str2 << endl;

    //? 2. using '+' operator

    cout << str1 + str2 << endl;
    cout << str1 << endl;
    cout << str2 << endl;

    cout << "--------------------------------------------------------" << endl;

    //! cpmparing two strings 

    string str3 = "abc";
    string str4 = "zzz";

    // 1. using compare operator 
    cout << str3.compare(str4) << endl;

    // 2. using relational operator 
    if(str3 > str4){
        cout << str3 << " is greater than " << str4 << endl;
    }
    else{
        cout << str4 << " is greater than " << str3 << endl;
    }
    cout << "--------------------------------------------------------" << endl;

    //! extracting a substring from a string using substr()

    string str5 = "helloworld";
    string str6 = "mississippi";
    string substr = str5.substr(2);  //* from which index to end of string
    cout << substr << endl;
    cout << str5.substr(5,3) << endl;   //* 2nd arguement for size

    cout << "--------------------------------------------------------" << endl;

    //! searching a substring from a string using find()

    cout << str6.find("si") << endl;
    cout << str6.rfind("si") << endl;
    cout << str6.find("hello") << endl;
    cout << string::npos << endl; //* returns a very big number equal to string::npos

    cout << "--------------------------------------------------------" << endl;

    //! converting a string into char array

    char* arr = (char*)str6.c_str();   // it will give a void pointer so wea are typecasting it to char*
    cout << arr << endl;
    cout << "--------------------------------------------------------" << endl;

    //! converting a char array into a string

    char a[] = "java coding";
    string str7(a);
    cout << str7 << endl;
    cout << "--------------------------------------------------------" << endl;
    
    string st(10, 'z');
	cout << st << endl;
    cout << "--------------------------------------------------------" << endl;

    //! reversing a string using reverse()

    reverse(str6.begin()+1 , str6.end()-2);
    cout << str6 << endl;

}