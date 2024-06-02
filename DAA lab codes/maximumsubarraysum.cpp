#include<iostream>
#include<climits>
using namespace std;

int crossSum(int arr[],int l,int mid,int h){
    int leftSubSum=INT_MIN;      // assigning highly small value approx. -infinity
    int rightSubSum=INT_MIN;      
    int sum=0;
    for(int i=mid;i>=l;i--){
        sum+=arr[i];
        leftSubSum = max(leftSubSum,sum);
    }

    sum = 0;

    for(int i=mid+1;i<=h;i++){
        sum+=arr[i];
        rightSubSum=max(rightSubSum,sum);       // TIME COMPLEXITY = theta(n logn)
    }
    return (rightSubSum + leftSubSum);
}

int maxSubarraySum(int arr[],int l,int h){
    if(l==h){
        return arr[l];
    }
    int mid=(l+h)/2;
    int leftsum=maxSubarraySum(arr,l,mid);
    int rightsum=maxSubarraySum(arr,mid+1,h);
    int csum=crossSum(arr,l,mid,h);
    int temp=max(leftsum,rightsum);
    return (max(temp,csum));
}

int main(){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Maximum Subarray Sum output for odd case of (-20,10,-30,40,-10,20,10,-50,40) :"<<endl;
    int arr[] = {-20,10,-30,40,-10,20,10,-50,40};
    cout<<maxSubarraySum(arr,0,8);
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"Maximum Subarray Sum output for even case of (-20,10,-20,30,20,-7,10,-30) :"<<endl;
    int arr2[] = {-20,10,-20,30,20,-7,10,-30};
    cout<<maxSubarraySum(arr2,0,7);
    cout<<endl<<"----------------------------------------------------"<<endl;
    return 0;
}