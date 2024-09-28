#include<bits/stdc++.h>
using namespace std;

class MinStack{
    public:
    stack<int>st;
    int minEle;
    
    void push(int x){
        if(st.size()==0){
            st.push(x);
            minEle = x;
        }
        else{
            if(x>=minEle){
                st.push(x);
            }
            else{
                st.push(2*x-minEle);
                minEle = x;
            }
        }
    }

    int pop(){
        if(st.size()==0)return -1;
        if(st.top()>=minEle){
            int ans = st.top();
            st.pop();
            return ans;
        }
        else{
            minEle = 2*minEle-st.top();
            int ans = st.top();
            st.pop();
            return ans;
        }
    }

    int getTop(){
        if(st.size()==0)return -1;
        if(st.top()>=minEle){
            return st.top();
        }
        else{
            return minEle;
        }
    }

    int getMin(){
        if(st.size()==0)return -1;
        else{
            return minEle;
        }
    }
};

int main(){
    MinStack st;
    st.push(1);
    st.push(10);
    st.push(3);
    st.push(-1);
    cout<<"Currently stack top = "<<st.getTop()<<endl;
    cout<<"Currently stack minimum = "<<st.getMin()<<endl;
    st.push(54);
    cout<<"Currently stack minimum = "<<st.getMin()<<endl;
    st.pop();
    cout<<"Currently stack top = "<<st.getTop()<<endl;
    st.pop();
    cout<<"Currently stack minimum = "<<st.getMin()<<endl;
    cout<<"Currently stack top = "<<st.getTop()<<endl;
}