class Solution {
private:
    int m;
    int n;
    int perimeter;

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));

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

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) return;

        if(grid[i][j] == 0 || visited[i][j] == true) return;

        visited[i][j] = true;

        if(i-1 < 0 || grid[i-1][j] == 0) perimeter++;
        if(i+1 >= m || grid[i+1][j] == 0) perimeter++;

        if(j-1 < 0 || grid[i][j-1] == 0) perimeter++;
        if(j+1 >= n || grid[i][j+1] == 0) perimeter++;

        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i, j+1);
    }
};