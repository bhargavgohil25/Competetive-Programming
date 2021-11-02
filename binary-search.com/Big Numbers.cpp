/* Given a two-dimensional integer matrix, return the total number of integers whose value is the largest in its row and in its column.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [1, 3, 2],
    [6, 6, 5],
    [1, 5, 7]
]
Output
3 */

int solve(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();

  vector<int> rowMax(n);
  vector<int> colMax(n);

  for (int i = 0; i < n; i++)
  {
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
      maxi = max(maxi, mat[i][j]);
    }
    rowMax[i] = maxi;
  }

  for (int i = 0; i < m; i++)
  {
    int maxi = INT_MIN;
    for (int j = 0; j < n; j++)
    {
      maxi = max(maxi, mat[j][i]);
    }
    colMax[i] = maxi;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] >= colMax[j] and mat[i][j] >= rowMax[i])
      {
        // cout << i << ' ' << j << endl;
        // cout << "colMax " << j << ": " << colMax[j] << endl;
        // cout << "rowMax " << i << ": " << rowMax[i] << endl;
        ans++;
      }
    }
  }
  cout << endl;
  return ans;
}
