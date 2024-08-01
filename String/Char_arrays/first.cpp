#include <bits/stdc++.h>
using namespace std;

int getLength(char arr[] , int n){
    int count = 0;
    int index = 0;
    while(arr[index++] != '\0')count++;
    return count;
}

int main(){
    // char arr[100];
    // cout<<"Enter name :"<<endl;
    // // cin>>arr;
    // cin.getline(arr,100);
    // cout<<"Your name is :"<<endl;
    // cout<<arr<<endl;
    // cout<<arr[0]<<"->"<<(int)arr[0]<<endl;
    // cout<<arr[1]<<"->"<<(int)arr[1]<<endl;
    // cout<<arr[2]<<"->"<<(int)arr[2]<<endl;
    // cout<<arr[3]<<"->"<<(int)arr[3]<<endl;
    // cout<<arr[4]<<"->"<<(int)arr[4]<<endl;
    // cout<<arr[5]<<"->"<<(int)arr[5]<<endl;
    // cout<<arr[6]<<"->"<<(int)arr[6]<<endl;


    // char arr[100];
    // cout << "Enter name : " << endl;
    // cin.getline(arr, 100,'\t');
    // cout<<"Your name is :"<<endl;
    // cout<<arr<<endl;


    char arr[100];
    cout<<"Enter name :"<<endl;
    cin.getline(arr,100);
    cout<<"Your name is :"<<endl;
    cout<<arr<<endl;
    cout<<"Length : "<<getLength(arr , 100);

}