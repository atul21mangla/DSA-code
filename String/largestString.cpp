#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter number of strings you want to enter";
    cin >> n;
    cin.ignore();
    cout << "------------------------------------------------------------------------------------" << endl;

    char inp[101];
    cout<<"enter 1st string :"<<endl;
    cin.getline(inp,101);

    char lsf[101];
    strcpy(lsf,inp);

    for(int i=2;i<=n;i++){
        cout<<"enter "<<i<<" string :"<<endl;
        cin.getline(inp,101);
        if(strcmp(inp,lsf)>0){
            strcpy(lsf , inp);
        }
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout<<"largets string among them is : "<<lsf<<endl;
}