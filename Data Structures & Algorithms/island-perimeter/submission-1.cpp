class Solution {
private:
    int m;
    int n;
    int perimeter;

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        perimeter = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1){
                    dfs(grid, visited, i, j);
                    return perimeter; 
                }
            }
        }

        return perimeter;

    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            perimeter++;
            return;
        }

        if(visited[i][j] == true) return;
        visited[i][j] = true;

        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i, j+1);
    }
};