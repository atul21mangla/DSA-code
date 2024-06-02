#include<iostream>
using namespace std;

typedef struct Node{
    float val,w;
    float ratio;
}Item;

int main(){
    Item a[] = {{60,10},{100,20},{120,30}};
    int n = 3;   // no. of objects
    int m = 50;  // capacity

    for(int i=0;i<n;i++){
        a[i].ratio=a[i].val/a[i].w;
    }
    float amt=0;
    
    for(int i=1;i<n;i++){
        Item key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j].ratio < key.ratio){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    
    for(int i=0;i<n;i++){
        if(a[i].w <= m){
            amt += a[i].val;
            m -= a[i].w;
        }
        else{
            amt += (m/a[i].w)*a[i].val;
            m = 0;
        }
    }
    cout<<"we have 3 objects with profit (60,100,120) with weight(10,20,30)"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Maximum profit we get from given objects and given constraints is = "<<amt<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    return 0;
}
