class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i=0,j=0;
        int sum=0;
        int res=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1<k){
                j++;
            }

            else if(j-i+1==k){
                int c = sum/k;
                if(c>=threshold)res++;
                j++;
                sum-=arr[i++];
            }
        }
        return res;
    }
};