class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n,false));
        int max {0};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    int curr {0};
                    dfs(grid, i , j, curr);
                    if(curr > max) max = curr;
                }
            }
        }

        return max;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& curr) {
        if(i < 0 || j < 0 || i >=m || j >= n) 
            return;
        
        if(grid[i][j] == 0 || visited[i][j] == true)
            return;

        visited[i][j] = true;
        curr++;

        dfs(grid, i+1, j, curr);
        dfs(grid, i-1, j, curr);
        dfs(grid, i, j+1, curr);
        dfs(grid, i, j-1, curr);
    }

private:
    vector<vector<bool>> visited;
    int m {0};
    int n {0};
};
