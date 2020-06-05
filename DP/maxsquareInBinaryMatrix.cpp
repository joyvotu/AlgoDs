int maximalSquare(vector<vector<char>>& matrix) {
       int n = matrix.size();
       if(n == 0)
           return 0;
       int m = matrix[0].size();
       int maxsize = 0;
       vector<vector<int>> dp(n,vector<int>(m));
       for(int row = 0;row<n;row++){
           for(int col = 0;col<m;col++){
               if(matrix[row][col] == '1'){
                   dp[row][col] = 1;
                   maxsize = 1;}
           }
       }
       for(int row = 1;row<n;row++){
           for(int col = 1;col<m;col++){
               if(matrix[row-1][col-1] == '1'
                  && matrix[row][col-1] == '1' && matrix[row-1][col] == '1' && matrix[row][col] == '1'){

                   dp[row][col] = min(min(dp[row-1][col-1],dp[row-1][col]),dp[row][col-1])+1;
                   if(dp[row][col]>maxsize)
                       maxsize = dp[row][col];

               }
           }
       }
       for(int row = 0;row<n;row++){
           for(int col = 0;col<m;col++){

               cout << dp[row][col] << " ";
           }
           cout << endl;
       }


       return maxsize*maxsize;
   }
};
