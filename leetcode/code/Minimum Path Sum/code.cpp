#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < n; ++i) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int h = 1; h < m; ++h) {
            for (int w = 1; w < n; ++w) {
                grid[h][w] += min(grid[h - 1][w], grid[h][w - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main()
{
    Solution su;
    su;
}