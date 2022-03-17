class Solution {
public:
    
    int r, c;
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         r = matrix.size();
         c = matrix[0].size();
        dp = vector<vector<int>>(r, vector<int> (c, 0));
        
        int maxL = 1;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                /*if(dp[i][j]!=0)
                    continue;
                for(auto d : dir)
                {
                    dp[i][j] = max(dp[i][j], dfs[i+d[0]][j+d[1]]);
                }*/
               maxL = max(maxL,dfs(i,j,matrix)); 
            }
        }
        return maxL;
    }
    
    int dfs(int x, int y, vector<vector<int>>& matrix)
    {
        if(dp[x][y]!=0) 
            return dp[x][y];
        int r = matrix.size();
        int c = matrix[0].size();
        for(auto d : dir)
            {
            int xx = x+d[0], yy = y+d[1];
            if(xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
            if(matrix[xx][yy] > matrix[x][y])
            {
                dp[x][y] = max(dp[x][y], dfs(xx,yy,matrix));
            }   
            }
        return ++dp[x][y];
        
    }
};