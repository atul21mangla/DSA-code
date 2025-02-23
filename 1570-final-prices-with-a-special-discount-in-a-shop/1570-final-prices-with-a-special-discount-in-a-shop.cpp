class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        st.push(0);
        for(int i=prices.size()-1;i>=0;i--){
            while(st.top()!=0 && st.top()> prices[i]){
                st.pop();
            }
            if(st.top()==0)st.push(prices[i]);
            else{
                int x = prices[i];
                prices[i] -= st.top();
                st.push(x);
            }
        }
        return prices;
    }
};