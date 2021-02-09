class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return;
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<n;i++){ // Diagonal Mirror
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};



// (0,0) => (2,0)
// (0,1) => (1,0)
// (0,2) => (0,0)
    
// (1,0) => (2,1)
// (1,1) => (1,1)
// (1,2) => (1,0)


// int N = A.size() ;
// if( N == 1 )return ; 

// for( int i = 0 ; i < N ; i++ )  // diagonal mirror 
// for( int j = 0 ; j < i ; j++ )
// swap( A[i][j] , A[j][i] );

// for( int j = 0 ; 2*j < N ; j++ ) // vertical mirror 
// for( int i = 0 ; i < N ; i++ )
// swap( A[i][j] , A[i][N-j-1] );
