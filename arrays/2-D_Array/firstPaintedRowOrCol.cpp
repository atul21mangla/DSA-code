// https://leetcode.com/problems/first-completely-painted-row-or-column/

#include<bits/stdc++.h>
using namespace std;

//! brute force

class Solution {
public:
    bool checkRowPainted(vector<vector<int>>& mat, int row) {
        for(int col = 0; col < mat[0].size(); col++) {
            if(mat[row][col] > 0) { //not painted
                return false;
            }
        }

        return true;
    }

    bool checkColPainted(vector<vector<int>>& mat, int col) {
        for(int row = 0; row < mat.size(); row++) {
            if(mat[row][col] > 0) { //not painted
                return false;
            }
        }

        return true;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // Brute Force
        
        unordered_map<int,pair<int,int>>mpp;
        int m = mat.size();
        int n = mat[0].size();
        int size = m*n;
        // storing row and col in mpp to access in O(1) time
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mpp[mat[i][j]] = {i,j};
            }  
        }

        // iterating over arr
        for(int i=0;i<size;i++){
            int row = mpp[arr[i]].first;
            int col = mpp[arr[i]].second;
            mat[row][col] *= -1; // to mark painted

            // now check whether current row or col is fully painted

            if(checkRowPainted(mat, row) || checkColPainted(mat, col)) {
                return i;
            }
        }
        return -1;
    }
};


//! Better Approach

//* T.C : O(m*n)
//? S.C : O((m*n) + m + n)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int,pair<int,int>>mpp;
        int m = mat.size();
        int n = mat[0].size();
        int size = m*n;
        // storing row and col in mpp to access in O(1) time
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mpp[mat[i][j]] = {i,j};
            }  
        }

        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);

        // iterating over arr
        for(int i=0;i<size;i++){
            int row = mpp[arr[i]].first;
            int col = mpp[arr[i]].second;
            mat[row][col] *= -1; // to mark painted

            // now check whether current row or col is fully painted
            rowCount[row]++;
            if(rowCount[row]==n)return i;
            colCount[col]++;
            if(colCount[col]==m)return i;
        }
        return -1;
    }
};


//! Optimal Approach
//? TC -> O(m*n)
//* SC -> O(m*n)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int,int>mpp;
        int m = mat.size();
        int n = mat[0].size();
        int size = m*n;
        // storing index of elements in mpp to access in O(1) time
        for(int i=0;i<size;i++){
            mpp[arr[i]] = i;
        }

        int minIdx = INT_MAX;
        for(int i=0;i<m;i++){
            int maxIdx = INT_MIN;
            for(int j=0;j<n;j++){
                int idx = mpp[mat[i][j]];
                maxIdx = max(maxIdx,idx);
            }  
            minIdx = min(maxIdx,minIdx);
        }

        for(int i=0;i<n;i++){
            int maxIdx = INT_MIN;
            for(int j=0;j<m;j++){
                int idx = mpp[mat[j][i]];
                maxIdx = max(maxIdx,idx);
            }  
            minIdx = min(maxIdx,minIdx);
        }

        return minIdx;

    }
};