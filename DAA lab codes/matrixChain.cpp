#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixOrder(const vector<int>& arr) {
    int n = arr.size();
    int minMul[n][n];
    for(int i = 1; i < n; i++) {
        minMul[i][i] = 0;
    }
    for(int diff = 2; diff < n; diff++) {
        for (int i = 1; i < n - diff + 1; i++) {
            int j = i + diff - 1;
            minMul[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++) {
                int q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if(q < minMul[i][j]) {
                    minMul[i][j] = q;
                }
            }
        }
    }
    return minMul[1][n - 1];
}

int main() {
    int size;
    cout << "Size of array: " << endl;
    cin >> size;
    vector<int> matOrder(size);
    cout << "Enter dimensions of matrices: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> matOrder[i];
    }
    cout<<"Multiplication answer is = ";
    cout << matrixOrder(matOrder);
    return 0;
}
