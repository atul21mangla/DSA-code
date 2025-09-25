class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i=0,j=n-1;
        int score=0;
        int max_score=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power -= tokens[i++];
                max_score = max(max_score,score);
            }
            else if(score>0){
                score--;
                power += tokens[j--];
            }
            else break;
        }

        return max_score;
    }
};