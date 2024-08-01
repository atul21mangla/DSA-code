#include<iostream>
using namespace std;

void printMatrix(int arr[][4] , int n , int m){
    cout<<"Normal Print of Matrix -------------------------------"<<endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;
}

void wavePrintMatrix(int arr[][4] , int n , int m){
    cout<<"Wave Print of Matrix -------------------------------"<<endl;
    for(int j = 0 ; j < m ; j++){  // column
        if(j % 2 == 0){  // down print hoga
            for(int i = 0 ; i < n ; i++){  // row
                cout<<arr[i][j]<<" ";
            }
            // cout<<endl;
        }
        else{
            for(int i = n - 1 ; i >= 0 ; i--){
                cout<<arr[i][j]<<" ";
            }
            // cout<<endl;
        }
        cout<<endl;
    }cout<<endl;
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row = 3;
    int col = 4;
    printMatrix(arr,row,col);
    wavePrintMatrix(arr,row,col);
    /*    |  |->|  |
          |  |  |  |
          |  |  |  |
          |->|  |->|
    */
}