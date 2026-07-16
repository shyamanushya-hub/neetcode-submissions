class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int islands {0};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    ++islands;
                    dfs(grid, i , j);
                }
            }
        }

        return islands;

    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >=m || j >= n) 
            return;
        
        if(grid[i][j] == '0' || visited[i][j] == true)
            return;

        visited[i][j] = true;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

private:
    
    vector<vector<bool>> visited;
    int m {0};
    int n {0};
};
