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
        // return mat;
        int li;
        int lj;
        int ui;
        int uj;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                li = max(0,i-k);
                lj = max(0,j-k);
                ui = min(i+k,r-1);
                uj = min(j+k,c-1);
                ans[i][j] = mat[ui][uj] - ((lj == 0) ? 0 : mat[ui][lj-1]) - ((li == 0) ? 0 : mat[li-1][uj]) + ((li==0 || lj==0) ? 0 : mat[li-1][lj-1]);
                
            }
        }
        return ans;
    }
};


// 1 2 3
// 4 5 6
// 7 8 9

