#include<iostream>
#include<climits>
using namespace std;

int maxArea(int arr[],int n){
    int i =0;
    int j = n-1;
    int max_area = INT_MIN;
    while(i<j){
        int area = (j-i)* min(arr[i],arr[j]);
        max_area = max(max_area , area);
        if(arr[i] < arr[j]){
            i++;
        }
        else j--;
    }
    return max_area;
}


int main(){
    int arr [] = {1,3,7,4,7,4,3,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxArea(arr,n);                            // AREA OF RECTANGLE = breadth * height
    return 0;                                                 //          = (j-1) * arr[i]
}
