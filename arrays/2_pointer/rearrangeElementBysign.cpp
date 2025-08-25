
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr){
    int n = arr.size();
    vector<int>ans(n);
    int posIdx = 0 , negIdx  = 1;
    for(int x:arr){
        if(x>0){
            ans[posIdx] = x;
            posIdx +=2;
        }
        else{
            ans[negIdx] = x;
            negIdx +=2;
        }
    }
    return ans;
}

vector<int> solve2(vector<int>& arr){   //! for variety - 2
    int n = arr.size();
    vector<int>pos,neg;
    for(int x:arr){
        if(x>0)pos.push_back(x);
        else neg.push_back(x);
    }

    int posIdx=0,negIdx=0;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        if(i%2==0){
            ans[i] = pos[posIdx++];
        }
        else
        ans[i] = neg[negIdx++];
    }
    return ans;
}

int main(){
    vector<int>arr = {3,1,-2,-5,2,-4};    //! variety -1  equal pos and neg elements
    // vector<int>arr = {1,2,-3,-1,-2,-3};  //? variety 2 not necessary to have same no. of pos and neg elements

    vector<int> ans = solve(arr);
    cout << "output " << endl;
    for(int x:ans){
        cout << x << " ";
    }cout<<endl;
    return 0;
}