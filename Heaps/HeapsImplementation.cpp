#include<bits/stdc++.h>
using namespace std;
class minHeap{
    private:
    vector<int>vec;
    public:

    void heapify(int i){
        int minIndex = i;
        int leftIndex = 2*i+1;
        if(leftIndex<vec.size() and vec[leftIndex] < vec[minIndex]){
            minIndex = leftIndex;
        }
        int rightIndex = 2*i+2;
        if(rightIndex < vec.size() and vec[rightIndex] < vec[minIndex]){
            minIndex = rightIndex;
        }
        if(minIndex!=i){
            swap(vec[minIndex],vec[i]);
            heapify(minIndex);
        }
    }

    void push(int val){
        vec.push_back(val);
        int childIndex = vec.size()-1;
        int parentIndex = (childIndex-1)/2;
        while(childIndex!=0 and vec[childIndex] < vec[parentIndex]){
            swap(vec[childIndex],vec[parentIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        return vec[0];
    }
    int size(){
        return vec.size();
    }
    bool isEmpty(){
        return vec.empty();
    }
};

class maxHeap{
    private:
    vector<int>vec;
    public:

    void heapify(int i){
        int maxIndex = i;
        int leftIndex = 2*i+1;
        if(leftIndex<vec.size() and vec[leftIndex] > vec[maxIndex]){
            maxIndex = leftIndex;
        }
        int rightIndex = 2*i+2;
        if(rightIndex < vec.size() and vec[rightIndex] > vec[maxIndex]){
            maxIndex = rightIndex;
        }
        if(maxIndex!=i){
            swap(vec[maxIndex],vec[i]);
            heapify(maxIndex);
        }
    }

    void push(int val){
        vec.push_back(val);
        int childIndex = vec.size()-1;
        int parentIndex = (childIndex-1)/2;
        while(childIndex!=0 and vec[childIndex] > vec[parentIndex]){
            swap(vec[childIndex],vec[parentIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        return vec[0];
    }
    int size(){
        return vec.size();
    }
    bool isEmpty(){
        return vec.empty();
    }

};

int main(){
    maxHeap mh;
    mh.push(1);
    mh.push(3);
    mh.push(2);
    mh.push(7);
    mh.push(5);
    mh.push(4);
    mh.push(6);
    mh.push(8);
    while(!mh.isEmpty()){
        cout<<mh.top()<<" ";
        mh.pop();
    }cout<<endl;
    return 0;
}