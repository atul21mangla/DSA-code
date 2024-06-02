#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[] = {-10,-20,-30,-50,-40};
    int n = sizeof(arr)/sizeof(int);
    int fl = INT_MIN;
    int sl = INT_MIN;
    int tl = INT_MIN;

    int fS=INT_MAX;
    int sS=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>fl){
            tl=sl;
            sl=fl;
            fl = arr[i];
        }
        else if(arr[i]>sl){
            tl=sl;
            sl=arr[i];
        }
        else if(arr[i]>tl){
            tl=arr[i];
        }

        if(arr[i]<fS){
            sS=fS;
            fS=arr[i];
        }
        else if(arr[i]<sS){
            sS=arr[i];
        }
    }

    int p1 = fl*sl*tl;
    int p2 = fS*sS*fl;
    cout<<max(p1,p2);
}