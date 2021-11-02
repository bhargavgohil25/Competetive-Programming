class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>>ans(r,vector<int>(c));
    int sum = 0;
    // generating the Prefix 2D sum 
    for(int i=0;i<r;i++){
      sum = 0;
      for(int j=0;j<c;j++){
        sum += mat[i][j];
        if(i > 0){
          mat[i][j] = mat[i-1][j] + sum;
        }else{
          mat[i][j] = sum;
        }
      }
    }
  }
};


// 1 2 3
// 4 5 6
// 7 8 9

