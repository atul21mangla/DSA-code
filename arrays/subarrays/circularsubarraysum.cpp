#include<iostream>
#include<climits>
using namespace  std;

int maxSubarray(int arr[] , int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int sum  = arr[0];
    int x = arr[0];
    int y = arr[0];
    for(int i=1;i<=n-1;i++){                         
        x = max(x + arr[i] , arr[i]);                  
        maxi = max(x , maxi);
        y = min(y + arr[i] , arr[i]);                  
        mini = min(y , mini);
        sum = sum + arr[i];
    }
    if(sum == mini){                 // if all elements of array are negative 
        return maxi;
    }
    return sum-mini;
}

int main(){
    int arr[6] = {1,2,-3,-4,5,6}; 
    cout<<"maximum subarray sum is :"<<endl;
    cout<<maxSubarray(arr , 6);
}
