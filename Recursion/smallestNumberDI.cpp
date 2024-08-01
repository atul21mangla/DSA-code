//! n<=8

#include<iostream>
using namespace std;

bool used[10] = {false};
bool flag = false;

void construct(string pattern,string result,int i){
    int n = pattern.length();
    // Base Case
    if(i == n){   // result.size() == pattern.size()+1
        cout << result << endl;
        flag = true;
        return;
    }

    // Recursive Case
    if(result.size()==0){
        for(int d=1;d<10;d++){
            result.push_back(d + '0');
            used[d] = true;
            construct(pattern,result,i);
            if(flag)return;
            used[d] = false;
			result.pop_back();
        }
    }

    int x = result.back() - '0';
    if(pattern[i] == 'I'){
        // next digit should be greater than x [x+1 , x+2 , ... , 9]
        for(int d=x+1;d<=9;d++){
            if(used[d]==false){
                result.push_back(d +'0');
                used[d] = true;
                construct(pattern,result,i+1);
                if(flag)return;
                used[d] = false;
                result.pop_back();
            }
        }
    }
    else{
        // next digit should be less than x [1 , 2 , ... , x-1]
        for(int d=1;d<=x-1;d++){
            if(used[d]==false){
                result.push_back(d +'0');
                used[d] = true;
                construct(pattern,result,i+1);
                if(flag)return;
                used[d] = false;
                result.pop_back();
            }
        }
    }
}

int main(){
    string pattern = "IDD";
    string result = "";
    construct(pattern,result,0);
    return 0;
}