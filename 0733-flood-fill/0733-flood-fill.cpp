class Solution {

private:
    void bfs(int row, int col, vector<vector<int>>& ans, int color,
             int initialColor) {
        int n = ans.size();
        int m = ans[0].size();

        vector<pair<int, int>> directions = {
            {-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

        ans[row][col] = color;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    ans[nx][ny] == initialColor) {
                    ans[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {

        int initialColor = image[sr][sc];

        if(initialColor == color)return image;

        bfs(sr, sc, image, color, initialColor);
        return image;
    }
};